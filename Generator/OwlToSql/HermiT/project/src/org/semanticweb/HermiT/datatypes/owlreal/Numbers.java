/* Copyright 2008, 2009, 2010 by the Oxford University Computing Laboratory
   
   This file is part of HermiT.

   HermiT is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   HermiT is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public License
   along with HermiT.  If not, see <http://www.gnu.org/licenses/>.
*/
package org.semanticweb.HermiT.datatypes.owlreal;

import java.math.BigDecimal;
import java.math.BigInteger;

public class Numbers {
    public static boolean isValidNumber(Number n) {
        return (n instanceof Integer) || (n instanceof Long) || (n instanceof BigInteger) || (n instanceof BigDecimal) || (n instanceof BigRational);
    }
    /**
     * Parses the given string into a Java Number object representing an integer.
     * The Java object is chosen such that .equals() works correctly across all Number-derived objects.
     */
    public static Number parseInteger(String string) throws NumberFormatException {
        try {
            return Integer.parseInt(string);
        }
        catch (NumberFormatException e) {
        }
        try {
            return Long.parseLong(string);
        }
        catch (NumberFormatException e) {
        }
        return new BigInteger(string);
    }
    /**
     * Parses the given string into a Java Number object representing an decimal.
     * The Java object is chosen such that .equals() works correctly across all Number-derived objects.
     */
    public static Number parseDecimal(String string) throws NumberFormatException {
        BigDecimal decimal=new BigDecimal(string);
        try {
            return decimal.intValueExact();
        }
        catch (ArithmeticException e) {
        }
        try {
            return decimal.longValueExact();
        }
        catch (ArithmeticException e) {
        }
        try {
            return decimal.toBigIntegerExact();
        }
        catch (ArithmeticException e) {
        }
        return decimal.stripTrailingZeros();
    }
    /**
     * Parses the given string into a Java Number object representing a rational.
     * The Java object is chosen such that .equals() works correctly across all Number-derived objects.
     */
    public static Number parseRational(String string) throws NumberFormatException {
        int divideIndex=string.indexOf('/');
        if (divideIndex==-1)
            throw new NumberFormatException("The string does not contain /.");
        BigInteger numerator=new BigInteger(string.substring(0,divideIndex));
        BigInteger denominator=new BigInteger(string.substring(divideIndex+1));
        if (denominator.compareTo(BigInteger.ZERO)<=0)
            throw new NumberFormatException("Invalid denumerator of the rational.");
        BigInteger gcd=numerator.gcd(denominator);
        numerator=numerator.divide(gcd);
        denominator=denominator.divide(gcd);
        if (denominator.equals(BigInteger.ONE)) {
            int numeratorBitCount=numerator.bitCount();
            if (numeratorBitCount<=32)
                return numerator.intValue();
            else if (numeratorBitCount<=64)
                return numerator.longValue();
            else
                return numerator;
        }
        try {
            return new BigDecimal(numerator).divide(new BigDecimal(denominator));
        }
        catch (ArithmeticException e) {
        }
        return new BigRational(numerator,denominator);
    }
    public static int compare(Number n1,Number n2) {
        if (n1.equals(n2))
            return 0;
        else if (n1.equals(MinusInfinity.INSTANCE) || n2.equals(PlusInfinity.INSTANCE))
            return -1;
        else if (n1.equals(PlusInfinity.INSTANCE) || n2.equals(MinusInfinity.INSTANCE))
            return 1;
        int typeN1=getNumberType(n1);
        int typeN2=getNumberType(n2);
        int maxType=Math.max(typeN1,typeN2);
        switch (maxType) {
        case 0: {
                int iv1=n1.intValue();
                int iv2=n2.intValue();
                return iv1<iv2 ? -1 : (iv1==iv2 ? 0 : 1);
            }
        case 1: {
                long lv1=n1.longValue();
                long lv2=n2.longValue();
                return lv1<lv2 ? -1 : (lv1==lv2 ? 0 : 1);
            }
        case 2: {
                BigInteger bi1=toBigInteger(n1,typeN1);
                BigInteger bi2=toBigInteger(n2,typeN2);
                return bi1.compareTo(bi2);
            }
        case 3: {
                BigDecimal bd1=toBigDecimal(n1,typeN1);
                BigDecimal bd2=toBigDecimal(n2,typeN2);
                return bd1.compareTo(bd2);
            }
        case 4: {
                BigRational br1=toBigRational(n1,typeN1);
                BigRational br2=toBigRational(n2,typeN2);
                return br1.compareTo(br2);
            }
        default:
            throw new IllegalArgumentException();
        }
    }
    protected static int getNumberType(Number n) {
        if (n instanceof Integer)
            return 0;
        else if (n instanceof Long)
            return 1;
        else if (n instanceof BigInteger)
            return 2;
        else if (n instanceof BigDecimal)
            return 3;
        else if (n instanceof BigRational)
            return 4;
        else
            throw new IllegalArgumentException();
    }
    protected static BigInteger toBigInteger(Number n,int nType) {
        switch (nType) {
        case 0:
        case 1:
            return BigInteger.valueOf(n.longValue());
        case 2:
            return (BigInteger)n;
        default:
            throw new IllegalArgumentException();
        }
    }
    protected static BigDecimal toBigDecimal(Number n,int nType) {
        switch (nType) {
        case 0:
        case 1:
            // We do not strip trailing zeros here! This is OK
            // because these numbers are used only during comparisons.
            return BigDecimal.valueOf(n.longValue());
        case 2:
            // We do not strip trailing zeros here! This is OK
            // because these numbers are used only during comparisons.
            return new BigDecimal((BigInteger)n);
        case 3:
            return (BigDecimal)n;
        default:
            throw new IllegalArgumentException();
        }
    }
    protected static BigRational toBigRational(Number n,int nType) {
        // The resulting rational is not necessary reduced!
        // This means that .equals() and .hashCode() need not
        // work properly. This, however, should not matter,
        // since the resulting object is used only in comparisons.
        switch (nType) {
        case 0:
        case 1:
            return new BigRational(BigInteger.valueOf(n.longValue()),BigInteger.ONE);
        case 2:
            return new BigRational((BigInteger)n,BigInteger.ONE);
        case 3: {
                BigDecimal decimal=(BigDecimal)n;
                // This method assumes that all BigDecimals actually have some decimal digits.
                assert decimal.scale()>0;
                return new BigRational(decimal.unscaledValue(),BigInteger.TEN.pow(decimal.scale()));
            }
        default:
            throw new IllegalArgumentException();
        }
    }
    
    public static enum BoundaryDirection {
        UPPER,LOWER
    }
    
    public static Number getNearestIntegerInBound(Number bound,BoundaryDirection boundaryDirection,boolean boundIsInclusive) {
        switch (getNumberType(bound)) {
        case 0:
            if (boundIsInclusive)
                return bound;
            else if (BoundaryDirection.LOWER.equals(boundaryDirection)) {
                int value=bound.intValue();
                if (value==Integer.MAX_VALUE)
                    return ((long)value)+1;
                else
                    return value+1;
            }
            else {
                int value=bound.intValue();
                if (value==Integer.MIN_VALUE)
                    return ((long)value)-11;
                else
                    return value-1;
            }
        case 1:
            if (boundIsInclusive)
                return bound;
            else if (BoundaryDirection.LOWER.equals(boundaryDirection)) {
                long value=bound.longValue();
                if (value==Long.MAX_VALUE)
                    return BigInteger.valueOf(value).add(BigInteger.ONE);
                else
                    return value+1;
            }
            else {
                long value=bound.longValue();
                if (value==Long.MIN_VALUE)
                    return BigInteger.valueOf(value).subtract(BigInteger.ONE);
                else
                    return value-1;
            }
        case 2:
            if (boundIsInclusive)
                return bound;
            else if (BoundaryDirection.LOWER.equals(boundaryDirection))
                return ((BigInteger)bound).add(BigInteger.ONE);
            else
                return ((BigInteger)bound).subtract(BigInteger.ONE);
        case 3: {
                // This method assumes that all BigDecimals actually have some decimal digits.
                BigDecimal bd=(BigDecimal)bound;
                assert bd.scale()>0;
                BigInteger bi=bd.toBigInteger();
                if (BoundaryDirection.LOWER.equals(boundaryDirection)) {
                    if (bd.compareTo(BigDecimal.ZERO)>0)
                        bi=bi.add(BigInteger.ONE);
                }
                else {
                    if (bd.compareTo(BigDecimal.ZERO)<0)
                        bi=bi.subtract(BigInteger.ONE);
                }
                int biBitCount=bi.bitCount();
                if (biBitCount<=32)
                    return bi.intValue();
                else if (biBitCount<=64)
                    return bi.longValue();
                else
                    return bi;
            }
        case 4: {
                // This method assumes that all BigRationals are not integers.
                BigRational br=(BigRational)bound;
                BigDecimal numerator=new BigDecimal(br.getNumerator());
                BigDecimal denominator=new BigDecimal(br.getDenominator());
                BigInteger quotient=numerator.divideToIntegralValue(denominator).toBigInteger();
                if (BoundaryDirection.LOWER.equals(boundaryDirection)) {
                    if (numerator.compareTo(BigDecimal.ZERO)>0)
                        quotient=quotient.add(BigInteger.ONE);
                }
                else {
                    if (numerator.compareTo(BigDecimal.ZERO)<0)
                        quotient=quotient.subtract(BigInteger.ONE);
                }
                int quotientBitCount=quotient.bitCount();
                if (quotientBitCount<=32)
                    return quotient.intValue();
                else if (quotientBitCount<=64)
                    return quotient.longValue();
                else
                    return quotient;
            }
        default:
            throw new IllegalArgumentException();
        }
    }
    public static int subtractIntegerIntervalSizeFrom(Number lowerBoundInclusive,Number upperBoundInclusive,int argument) {
        if (argument<=0)
            return 0;
        if (lowerBoundInclusive.equals(upperBoundInclusive))
            return argument;
        int typeLowerBound=getNumberType(lowerBoundInclusive);
        int typeUpperBound=getNumberType(upperBoundInclusive);
        int maxType=Math.max(typeLowerBound,typeUpperBound);
        switch (maxType) {
        case 0: {
                int size=upperBoundInclusive.intValue()-lowerBoundInclusive.intValue()+1;
                if (size<=0)
                    return 0;
                else
                    return Math.max(argument-size,0);
            }
        case 1: {
                long size=upperBoundInclusive.longValue()-lowerBoundInclusive.longValue()+1;
                if (size<=0L)
                    return 0;
                else
                    return (int)Math.max(((long)argument)-size,0);
            }
        case 2: {
                BigInteger leftover=BigInteger.valueOf(argument).subtract(toBigInteger(upperBoundInclusive,typeUpperBound)).add(toBigInteger(lowerBoundInclusive,typeLowerBound)).subtract(BigInteger.ONE);
                if (leftover.compareTo(BigInteger.ZERO)<=0)
                    return 0;
                else
                    return leftover.intValue();
            }
        default:
            throw new IllegalArgumentException();
        }
    }
    public static Number nextInteger(Number integer) {
        switch (getNumberType(integer)) {
        case 0: {
                int value=integer.intValue();
                if (value==Integer.MAX_VALUE)
                    return ((long)value)+1;
                else
                    return value+1;
            }
        case 1: {
                long value=integer.longValue();
                if (value==Long.MAX_VALUE)
                    return BigInteger.valueOf(value).add(BigInteger.ONE);
                else
                    return value+1;
            }
        case 2:
            return ((BigInteger)integer).add(BigInteger.ONE);
        default:
            throw new IllegalArgumentException();
        }
    }
}
