#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <QTextStream>
#include <QDebug>
#include <QVector>
#include <algorithm>

struct Vertex
{
    int subtree_size;
    QVector<int> nbrs;
    QVector<int> children;

    Vertex()
        : subtree_size(1)
    {}
};



struct Solution
{
    void input(QTextStream &in)
    {
        in >> N;
        vertexes.resize(N + 1);

        for (int i = 0; i < (N - 1); ++i)
        {
            int X, Y;
            in >> X >> Y;

            vertexes[X].nbrs.push_back(Y);
            vertexes[Y].nbrs.push_back(X);
        }
    }

    void removeByValue(QVector<int> &vec, int value)
    {
        vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
    }

    void recMakeBinTree(int id)
    {
        //qDebug() << "recMakeBinTree( " << id << ")";

        if ( vertexes[id].children.size() == 0 )
            return;

        if ( vertexes[id].children.size() == 1 )
        {
            answer += vertexes[ vertexes[id].children[0] ].subtree_size;
            return;
        }

        while ( vertexes[id].children.size() > 2 )
        {
            int min_id = vertexes[id].children[0];
            for (int i = 1; i < vertexes[id].children.size(); ++i)
            {
                int cur_id = vertexes[id].children[i];

                if ( vertexes[cur_id].subtree_size < vertexes[min_id].subtree_size )
                    min_id = cur_id;
            }

            answer += vertexes[ min_id ].subtree_size;
            removeByValue( vertexes[id].children, min_id );
        }

        recMakeBinTree( vertexes[id].children[0] );
        recMakeBinTree( vertexes[id].children[1] );
    }

    int recLayOut(int id, int parent)
    {
        vertexes[id].children.clear();
        for (int i = 0; i < vertexes[id].nbrs.size(); ++i)
            if ( vertexes[id].nbrs[i] != parent )
                vertexes[id].children.push_back( vertexes[id].nbrs[i] );

        vertexes[id].subtree_size = 1;
        for (int i = 0; i < vertexes[id].children.size(); ++i)
            vertexes[id].subtree_size += recLayOut(vertexes[id].children[i], id);

        return vertexes[id].subtree_size;
    }

    void solve()
    {
        //qDebug() << "Solve..";

        int true_answer = 2 * N;

        for (int root = 1; root <= N; ++root)
        {
            //qDebug() << "  root = " << root;
            recLayOut(root, root);

            answer = 0;
            recMakeBinTree(root);

            true_answer = qMin(true_answer, answer);
        }

        answer = true_answer;

        /*QVector<bool> was(N + 1, false);
        int processed = 0;
        int root;

        while ( processed < (N - 1) )
        {
            for (int j = 1; j <= N; ++j)
                if ( !was[j] )
                {
                    if ( vertexes[j].nbrs.size() <= 1 )
                    {
                        // its a list
                        int parent = vertexes[j].nbrs[0];

                        //was[parent] = true;

                        vertexes[parent].children.push_back(j);
                        removeByValue(vertexes[parent].nbrs, j);
                        vertexes[parent].subtree_size += vertexes[j].subtree_size;

                        was[j] = true;
                        ++processed;

                        root = parent;

                        if ( processed == (N - 1) )
                            break;
                    }
                }
        }

        qDebug() << "Root is " << root;

        recMakeBinTree(root);*/


    }

    void output(QTextStream &out)
    {

        out << answer << "\n";
    }

protected:
    // input:
    int N;
    QVector<Vertex> vertexes;

    // output:
    int answer;
};

#endif // SOLUTION_HPP
