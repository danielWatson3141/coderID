#include <QTextStream>
#include <QFile>
#include <QStringList>
#include <QString>
#include <QVector>
#include <QtGlobal>

#include <QDebug>

#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>

int compareFlows(int L, QStringList initialFlows, QStringList deviceFlows);
int compareFlows(int L, int pos, int changes, int best, QStringList initialFlows, QStringList deviceFlows);
bool compareFlows(QStringList initialFlows, QStringList deviceFlows);

int main(int argc, char** argv)
{
  QFile inFile("../input/input.txt");
  if(!inFile.open(QIODevice::ReadOnly)) {
    qDebug() <<  "ReadError:" << inFile.errorString();
    return -1;
  }
  QTextStream in(&inFile);
  QFile outFile("../input/output.txt");
  if(!outFile.open(QIODevice::WriteOnly)) {
    qDebug() <<  "WriteError:" << outFile.errorString();
    return -1;
  }
  QTextStream out(&outFile);
  out.setRealNumberNotation(QTextStream::FixedNotation);
  out.setRealNumberPrecision(7);
  int numberOfCases = in.readLine().toInt();
  qDebug() << "Cases:" << numberOfCases;
  for (int c = 1; c <= numberOfCases; ++c)
  {
    QStringList parameters = in.readLine().split(" ");
    int N = parameters[0].toInt();
    int L = parameters[1].toInt();
    qDebug() << "N = " << N << "L = " << L;
    QStringList initialFlowsList = in.readLine().split(" ");
    Q_ASSERT(initialFlowsList.size() == N);
    qDebug() << initialFlowsList;
    QStringList deviceFlowsList = in.readLine().split(" ");
    Q_ASSERT(initialFlowsList.size() == N);
    qDebug() << deviceFlowsList;
    int result = compareFlows(L, initialFlowsList, deviceFlowsList);
    if (result == -1)
    {
      out << "Case #" << c << ": " << "NOT POSSIBLE" << endl;
    }
    else
    {
      out << "Case #" << c << ": " << result << endl;
    }
  }
  inFile.close();
  outFile.close();
  return 0;
}

int compareFlows(int L, QStringList initialFlows, QStringList deviceFlows)
{
  if (compareFlows(initialFlows, deviceFlows))
  {
    return 0;
  }
  return compareFlows(L, 0, 0, -1, initialFlows, deviceFlows);
}

int compareFlows(int L, int pos, int changes, int best, QStringList initialFlows, QStringList deviceFlows)
{
  int ret = -1;
  if (pos < L)
  {
    if (pos < (L -1))
    {
      ret = compareFlows(L, pos + 1, changes, best, initialFlows, deviceFlows);
    }
    QStringList tmp = initialFlows;
    for (int i = 0; i < tmp.size(); ++i)
    {
      if (tmp[i].at(pos) == QChar('1'))
      {
	tmp[i].replace(pos, 1, QChar('0'));
      }
      else
      {
	tmp[i].replace(pos, 1, QChar('1'));
      }
    }
    if (compareFlows(tmp, deviceFlows))
    {
      if ((ret == -1) || ((changes + 1) < ret))
      {
	ret = changes + 1;
      }
    }
    else if (pos < (L - 1))
    {
      int res = compareFlows(L, pos + 1, changes + 1, best, tmp, deviceFlows);
      if ((res != -1) && ((ret == -1) || (res < ret)))
      {
	ret = res;
      }
    }
  }
  if ((best != -1) && ((ret == -1) || (ret > best)))
  {
    return best;
  }
  return ret;
}

bool compareFlows(QStringList initialFlows, QStringList deviceFlows)
{
  for (int i = 0; i < deviceFlows.size(); ++i)
  {
    if (!initialFlows.contains(deviceFlows[i]))
    {
      return false;
    }
  }
  return true;
}