#ifndef matrix_h_
#define matrix_h_

struct matrix
{
  double **data;
  
  int rows;

  int cols;

  matrix ()
  {
    rows = cols = 0;
    data = NULL;
  }

  ~matrix ()
  {
    int y;
    if (data != NULL)
    {
      for (y = 0; y < rows; ++y)
      {
        delete [] data[y];
      }
      delete [] data;
    }
  }

  matrix (int r, int c)
  {
    int y, x;
    rows = r;
    cols = c;

    data = new double*[rows];
    for (y = 0; y < rows; ++y)
    {
      data[y] = new double[cols];
      for (x = 0; x < cols; ++x)
      {
        data[y][x] = 0.0f;
      }
    }
  }

  void resize (int r, int c)
  {
    int x, y;
    if (data != NULL)
    {
      for (y = 0; y < rows; ++y) 
      {
        delete [] data[y];
      }
      delete [] data;
    }

    rows = r;
    cols = c;
    data = new double*[rows];
    for (y = 0; y < rows; ++y)
    {
      data[y] = new double[cols];
      for (x = 0; x < cols; ++x)
      {
        data[y][x] = 0.0f;
      }
    }
  }

  double& at(int row, int col)
  {
    return data[row][col];
  }


  bool matrixMult (matrix &val1, matrix &val2, matrix &out)
  {
    int m1, m2, n1, n2, x2, y1, z;
    double sum;
    m1 = val1.rows;
    m2 = val2.rows;

    if (m1 < 1 || m2 < 1)
    {
      return false;
    }

    n1 = val1.cols;
    n2 = val2.cols;

    if (n1 < 1 || n2 < 1 || n1 != m2)
    {
      return false;
    }

    for (y1 = 0; y1 < m1; ++y1)
    {
      for (x2 = 0; x2 < n2; ++x2)
      {
        sum = 0.0f;
        for (z = 0; z < n1; ++z)
        {
          sum += val1.at(y1, z) * val2.at(z, x2);
        }
        out.at(y1, x2) = sum;
      }
    }
    return true;
  }


  bool matrixMult (matrix &val1, double &mult, matrix &out)
  {
    int m1, n1, x1, y1;
    m1 = val1.rows;
    if (m1 < 1)
    {
      return false;
    }

    n1 = val1.cols;
    if (n1 < 1)
    {
      return false;
    }

    for (y1 = 0; y1 < m1; ++y1)
    {
      for (x1 = 0; x1 < n1; ++x1)
      {
        out.at(y1, x1) = val1.at(y1, x1) * mult;
      }
    }

    return true;
  }


  bool matrixAdd (matrix &val1, matrix &val2, matrix &out)
  {
    int m1, m2, n1, n2, x1, y1;
    m1 = val1.rows;
    m2 = val2.rows;

    if (m1 < 1 || m2 < 1 || m1 != m2)
    {
      return false;
    }

    n1 = val1.cols;
    n2 = val1.cols;

    if (n1 < 1 || n2 < 1 || n1 != n2)
    {
      return false;
    }

  //    out.resize (m1, n1);

    for (y1 = 0; y1 < m1; ++y1)
    {
      for (x1 = 0; x1 < n1; ++x1)
      {
        out.at(y1, x1) = val1.at(y1, x1) + val2.at(y1, x1);
      }
    }

    return true;
  }


  bool matrixTrans (matrix &val1, matrix &out)
  {
    int m1, n1, x1, y1;
    double val;
    m1 = val1.rows;
    if (m1 < 1)
    {
      return false;
    }

    n1 = val1.cols;
    if (n1 < 1)
    {
      return false;
    }

  //    out.resize (n1, m1);

    for (y1 = 0; y1 < m1; ++y1)
    {
      for (x1 = 0; x1 < n1; ++x1)
      {
        val = val1.at(y1, x1);
        out.at(x1, y1) = val;
      }
    }

    return true;
  }


    //! Based on gaussj from "Numerical Recipes in C"
    //!
  bool matrixInv (matrix &val1, matrix &out)
  {
    int *indxc, *indxr, *ipiv;
    int i, icol, irow, j, k, l, ll;
    int x, y, n = val1.rows;
    double big, dum, pivinv, temp;

    if (val1.rows < 1 || val1.rows != val1.cols)
    {
      return false;
    }

    //! Index and pivot tables
    indxc = new int[n]; //ivector(1,n);
    indxr = new int[n]; //indxr=ivector(1,n);
    ipiv = new int[n]; //ipiv=ivector(1,n);

    //! Create a copy of our input vector for in-line inversion
    for (y = 0; y < n; ++y)
    {
      for (x = 0; x < n; ++x)
      {
        temp = val1.at(y, x);
        out.at(y, x) = temp;
      }
    }

    for (j = 0; j < n; ++j)
    {
      ipiv[j] = 0;
    }

    for (i = 0; i < n; ++i)
    {
      big = 0.0f;
      for (j = 0; j < n; ++j)
      {
        if (ipiv[j] != 1)
        {
          for (k = 0;k < n; ++k)
          {
            if (ipiv[k] == 0)
            {
              if (fabs(out.at(j, k)) >= big)
              {
                big = fabs(out.at(j, k));
                irow = j;
                icol = k;
              }      
            } // if (ipiv[k] == 0)
            else if (ipiv[k] > 1)
            {
  //           nrerror("GAUSSJ: Singular Matrix-1");
            }
          } // for (k=1;k<=n;k++)
        } // if (ipiv[j] != 1)
      } // for (j=1;j<=n;j++)

      ++(ipiv[icol]);
      if (irow != icol)
      {
        for (l = 0; l < n; ++l)
        {
          temp = out.at(irow, l);
          out.at(irow, l) = out.at(icol, l);
          out.at(icol, l) = temp;
        }
      }

      indxr[i] = irow;
      indxc[i] = icol;
      temp = fabs(out.at(icol, icol));
      if (temp < 0.00000001)
      {
  //        exception ("matrixInv", "Singular Matrix:2");
      }

      pivinv = 1.0 / out.at(icol, icol);
      out.at(icol, icol) = 1.0;

      for (l = 0; l < n; ++l)
      {
        temp = out.at(icol, l) * pivinv;
        out.at(icol, l) = temp;
      }

      for (ll = 0; ll < n; ++ll)
      {
        if (ll != icol) 
        {
          dum = out.at(ll, icol);
          out.at(ll, icol) = 0.0f;

          for (l = 0; l < n; ++l)
          {
            temp = out.at (ll, l) - (out.at(icol, l) * dum);
            out.at(ll, l) = temp;
          }
        }
      } // for (ll = 0; ll < n; ++ll)
    } // for (i = 0; i < n; ++i)

    for (l = n-1; l >= 0; --l)
    {
      if (indxr[l] != indxc[l])
      {
        for (k = 0; k < n; ++k)
        {
          temp = out.at(k, indxr[l]);
          out.at(k, indxr[l]) = out.at(k, indxc[l]);
          out.at(k, indxc[l]) = temp;
        }
      }
    }

    delete [] ipiv;
    delete [] indxr;
    delete [] indxc;

    return true;
  }


  bool matrixPseudoInv (matrix &in, matrix &out)
  {
    matrix in_T, inTin, inTinInv;
    bool state;

    state = matrixTrans (in, in_T);

    state = state ? matrixMult (in_T, in, inTin) : state;
    state = state ? matrixInv (inTin, inTinInv) : state;
    state = state ? matrixMult (inTinInv, in_T, out) : state;
    return state;
  }


};




#endif