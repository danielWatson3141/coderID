#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <QTextStream>
#include <QDebug>

#include <QString>
#include <QVector>
#include <algorithm>
#include <cmath>

struct Solution
{
    void readVector(QTextStream &in, QVector<QString> &vec)
    {
        vec.resize(N);

        for (int i = 0; i < N; ++i)
        {
            in >> vec[i];
        }

        in.readLine();
    }

    void input(QTextStream &in)
    {
        in >> N >> L;
        readVector(in, outlets);
        readVector(in, devices);
    }

    QVector<QString> doFlip(QVector<QString> vec, int flip_mask)
    {
        for (int j = 0; j < L; ++j)
        {
            if ( flip_mask & 1 )
            {
                for (int i = 0; i < N; ++i)
                    vec[i][j] = QChar('1' - (vec[i][j].toLatin1() - '0'));

            }

            flip_mask >>= 1;
        }

        std::sort(vec.begin(), vec.end());
        return vec;
    }

    int ones(int flip_mask)
    {
        int tmp = 0;

        for (int j = 0; j < L; ++j)
        {
            tmp += (flip_mask & 1);
            flip_mask >>= 1;
        }

        return tmp;
    }

    void solve()
    {

        std::sort(devices.begin(), devices.end());
        std::sort(outlets.begin(), outlets.end());

        answer = L + 2;
        int max_flip_mask = std::pow(2, L);
        for (int fm = 0; fm < max_flip_mask; ++fm)
            if ( doFlip(outlets, fm) == devices )
            {
                answer = qMin( ones(fm), answer );
            }
    }

    void output(QTextStream &out)
    {
        if (answer == (L + 2))
        {
            out << "NOT POSSIBLE\n";
        }
        else
        {
            out << answer << "\n";
        }
    }

protected:
    // input:
    int N, L;
    QVector<QString> outlets, devices;

    // output:
    int answer;

};

#endif // SOLUTION_HPP
