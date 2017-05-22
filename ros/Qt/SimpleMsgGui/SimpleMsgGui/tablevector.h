#ifndef TABLEVECTOR_H
#define TABLEVECTOR_H
#include <QTableWidget>
#include <sstream>
//#include <type_traits> // C++11  use std::
#include <tr1/type_traits> // C++03, use std::tr1

#define StdVector
#ifndef RVector
#ifdef StdVector
#include <vector>
#define RVector  std::vector
#else
#include <QVector>
#define RVector  std::vector
#endif
#endif
template<typename T>
class TableVectorT : public RVector<RVector< T * > >
{
public:
    TableVectorT<T>(){}
    TableVectorT<T>(size_t rows, size_t cols)
    {
        this->resize(rows);
        for(size_t i=0; i<rows; i++)
            for(size_t j= 0; j< cols; j++)
                this->at(i).push_back( new T);
    }
    std::string Dump()
    {
        std::stringstream tmp;
        for(size_t i= 0; i< this->size(); i++)
        {
            RVector< T * > myrow(this->at(i));
            for(size_t j= 0; j< myrow.size(); j++)
            {
                tmp << myrow[j]->text().toStdString() << ":";
            }
            tmp << "\n";
        }
        return tmp.str();
    }

    template<typename U>
    void Fill(RVector<RVector< U > > & t)
    {
        if(this->size() < t.size())
            throw;
        for(size_t i= 0; i< t.size(); i++)
        {
            RVector< U > row(t[i]);
            Fill<U>(row, i);
#if 0
            RVector< T * > myrow(this->at(i));
            for(size_t j= 0; j< row.size(); j++)
            {
                std::stringstream str;
                str << row[j];
                myrow[j]->setText(QString::fromStdString(str.str()));
            }
#endif
        }
    }
    template<typename U>
    void Fill(RVector< U > &  t, size_t rownum)
    {
        RVector< T * > myrow(this->at(rownum));
        for(size_t i= 0; i< t.size(); i++)
        {
            std::stringstream str;
            str << t[i];
            myrow[i]->setText(QString::fromStdString(str.str()));
        }
    }
    size_t RowNum(std::string name)
    {
        return rownames[name];
    }
    void SetRowNames(QStringList list)
    {
        size_t i=0;
        foreach( QString str, list) {
            rownames[str.toStdString()]=i++;
        }
    }
    void SetRowNames(std::vector<std::string> list)
    {
        for(size_t i=0;i< list.size(); i++){
            rownames[list[i]]=i;
        }
    }
    template<typename U>
    void Fill(RVector< U >  t, std::string & rowname)
    {
        RVector< T * > myrow(this->at(rownames[rowname]));
        for(size_t i= 0; i< t.size(); i++)
        {
            std::stringstream str;
            str << t[i];
            myrow[i]->setText(QString::fromStdString(str.str()));
        }
    }
    //////////////////////////////////////////
    std::map<std::string, size_t> rownames;
};

typedef TableVectorT<QTableWidgetItem> QTableItems;

#endif // TABLEVECTOR_H
