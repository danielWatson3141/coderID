package tw.joecwu.contest.gcj2014.round1a

import grizzled.slf4j.Logging
import java.io.{BufferedReader, File, PrintWriter}
import scala.io.Source
import scala.Array
import scala.math._
import scalaz._
import Scalaz._

/**
 * Created by joewu on 4/25/14.
 */
object ProblemA extends Logging {
  case class Questions(q:Int, n:Int, l:Int, init:Array[String], target:Array[String])


  val output = new PrintWriter(new File("2014r1a_resultA.out"))

  def main(args : Array[String]) {
    info("Start Fighting!!!")
    val file = Source.fromURL(getClass().getResource("/2014/r1a/smallA.in"))

    val reader = file.bufferedReader()

    val total = reader.readLine().toInt

    info(s"Case Count: $total")

    var i = 0;
    val qs = {for( i <- 1 to total) yield parseQuestions(i, reader)}.toList

    qs.map{ q=>
      info(s"Q #${q.q} => ${q.n} ${q.l}")
      val result = solveQuestions(q)
      info(s"Case #${q.q}: ${result}")
      output.write(s"Case #${q.q}: ${result}\r\n")
    }

    file.close()
    output.close()
  }

  def parseQuestions(i: Int, reader: BufferedReader) = {

    val line1 = reader.readLine().split(' ')
    val init = reader.readLine().split(' ')
    val target = reader.readLine().split(' ')

    Questions(i,line1(0).toInt,line1(1).toInt,init,target)
  }

  def solveQuestions(q:Questions) : String = {
    debug(s"n:${q.n} l:${q.l}")

    val sortedTarget = q.target.toList.sortWith((a,b)=>a>b).toArray
    debug("Sorted Target:"+sortedTarget.mkString(","))

    var o = q.init.toList.sortWith((a,b)=>a>b).toArray
//    var count = 0
    if(checkSame(sortedTarget,o)) return "0"

    val result = sortedTarget.map{ s =>
      var count = Int.MaxValue
      for(i <- 0 to o.length-1){
        val sample = o(i)
        val cPositions = diff(s,sample)
        debug("diff:"+cPositions.mkString(","))
        val result = o.map{ i =>
          var tmp = i
          cPositions.map{ p =>
            tmp = updateChar(tmp,p)
          }
          tmp
        }.sortWith((a,b)=>a>b).toArray
        if(checkSame(sortedTarget,result))
          count = min(count,cPositions.length)
      }
      count
    }.sortWith((a,b)=>a<b)(0)

    if(result.equals(Int.MaxValue))
      "NOT POSSIBLE"
    else
      result.toString

    //    var aa = q.init.toList.sortWith((a,b)=>a>b).toArray
//    for(i <- 0 to q.l-1){
//      aa = o.map{ n =>
//        val newN = if(n(i)=='0') '1' else '0'
//        updateChar(n,i,newN)
//      }.sortWith((a,b)=>a>b).toArray
//      count = 1
//      if(checkSame(sortedTarget,aa)) return count.toString
//    }
//
//    for(i <- 0 to q.l-1){
//      o = o.map{ n =>
//        val newN = if(n(i)=='0') '1' else '0'
//        updateChar(n,i,newN)
//      }.sortWith((a,b)=>a>b).toArray
//      count = i+1
//      if(checkSame(sortedTarget,o)) return count.toString
//      for(y <- i+1 to q.l-1){
//        debug(s"i:$i,y:$y")
//        val bb = o.map{ n =>
//          val newN = if(n(y)=='0') '1' else '0'
//          updateChar(n,y,newN)
//        }.sortWith((a,b)=>a>b).toArray
//        debug("AA:"+o.mkString(","))
//        debug("BB:"+bb.mkString(","))
//        count = count + 1
//        if(checkSame(sortedTarget,bb)) return count.toString
//
//      }
//    }
//    "NOT POSSIBLE"
  }

  def updateChar(s:String,p:Int) : String = {
    val c = if(s(p)=='0') '1' else '0'
//    debug(s"s:$s, p:$p, c:$c")
    if(p==0)
      c.toString + s.substring(1)
    else if(p==s.length-1){
      s.substring(0,s.length-1)+c.toString
    }else{
      s.substring(0,p)+c.toString+s.substring(p+1)
    }
  }

  def checkSame(a:Array[String], b:Array[String]) : Boolean = {
    for(i <- 0 to a.length-1){
      if(!a(i).equals(b(i))) return false
    }
    true
  }

  def diff(a:String, b:String) : List[Int] = {
    val aa = for(i <- 0 to a.length-1) yield {
      if(!a(i).equals(b(i)))
        Some(i)
      else
        None
    }
    aa.toList.flatten
  }
}
