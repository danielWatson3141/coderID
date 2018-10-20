#include <QSet>
#include <QString>
#include <QQueue>
#include <iostream>
#include <string>
#include <QStringList>
using namespace std;


uint qHash(const QStringList& list)
{
    return qHash(list.join(","));
}

void branch(int len, QStringList item, QQueue<QStringList>& queue,  QHash<QStringList, int >& been, int level)
{
    for(int i=0; i<len; ++i )
    {
        QStringList temp;
        QListIterator<QString> it(item);
        while(it.hasNext())
        {
            QString str  = it.next();
            if ( str[i] == '0' )
            {
                str[i] = '1';
            }
            else
            {
                str[i] = '0';
            }
            temp.append(str);
        }
        if (!been.contains(temp))
        {
            been.insert(temp, level);
            queue.push_back(temp);
        }
    }
}



int process(int len, QStringList begin, const QSet<QString>& answer)
{
    QHash<QStringList,int > been;
    QQueue<QStringList > queue;

    been.insert(begin,0);
    queue.append(begin);

    while(!queue.isEmpty())
    {
        QStringList& item = queue.front();
        queue.pop_front();
        int nstep = been[item];
        if (item.toSet() == answer)
        {
            return nstep;
        }
        branch(len, item, queue, been, nstep+1);
    }
    return -1;
}



int main()
{
    int ncases;
    cin >> ncases;
    for(int icase=0; icase<ncases;++icase)
    {
        int nstr;
        int strlen;
        cin >> nstr >> strlen;
        string str;
        QList<QString> begin;
        QSet<QString> answer;
        for(int i=0; i<nstr;++i)
        {
            cin >> str;
            begin.append(QString::fromStdString(str));
        }
        for(int i=0; i<nstr;++i)
        {
            cin >> str;
            answer.insert(QString::fromStdString(str));
        }

        if (begin.toSet() == answer)
        {
            std::cout << "Case #" << icase+1 << ": " << 0 << endl;
        }
        else
        {
            int num = process(strlen, begin, answer);
            if (num == -1)
            {
                cout << "Case #" << icase+1 << ": " << "NOT POSSIBLE" << endl;
            }
            else
            {
                cout << "Case #" << icase+1 << ": " << num << endl;
            }

        }
    }

    return 0;
}
