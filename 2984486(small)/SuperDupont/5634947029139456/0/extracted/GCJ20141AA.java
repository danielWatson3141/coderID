/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package gcj20141aa;

import java.io.*;
import java.util.regex.Pattern;

/**
 *
 * @author Nous
 */
public class GCJ20141AA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)throws IOException
    {
        // TODO code application logic here
        Reader rr;
        Writer ww;
        LineNumberReader Lnr;
        String s;
        String[][] TTabs;
        long a,b,c;
        int i,j,k,m,n, ntc;
        Pattern pat;

         TTabs = new String[100][];

        int NbTestCases;
        String sout;
        int  FlagOK,FlagOK2;

        // Pi x 10e30, au cas où :
        // BigNbr bnPIe30;
        // bnPIe30 = new BigNbr("3141592653589793238462643383279");

        // Variables Fonctionnelles liées au Test Case :
        int Nin, Lin;
        long[] Puis2;
        int[][] Outlets, Devices;
        int[][] DifDOi;
        long [][] DifDOl;
        int nbdif;
        long lgdif;
        
        Puis2 = new long [40];
        Outlets = new int[150][40];
        Devices = new int [150][40];
        DifDOi = new int [150][150];
        DifDOl = new long [150][150];
        
 
        //       ll=new long[100];
        pat =  Pattern.compile(" +"); // Pour séparer les mots
        //       pat =  Pattern.compile(" *"); // Pour séparer chaque caractère
        //               (attention : commence alors par "")
        // Titre
        System.out.println("2014-1A-A");

        // Nombre de cas
        rr=new InputStreamReader(new FileInputStream("A-small-attempt0.in"),
                "ISO-8859-1");
        ww=new OutputStreamWriter(new FileOutputStream("File.out"),
                "ISO-8859-1");
        Lnr = new LineNumberReader(rr);
        NbTestCases = Integer.parseInt(Lnr.readLine());

        // Cas par cas
        for(ntc=1;ntc<=NbTestCases;ntc++)
        {
            // Début du cas
            s=Lnr.readLine();
            TTabs[0] = pat.split(s);

            Nin = Integer.parseInt(TTabs[0][0]);
            Lin = Integer.parseInt(TTabs[0][1]);

            // Lire l'ensemble des Outlets
            s=Lnr.readLine();
            TTabs[0] = pat.split(s);
            for(i=0;i<Nin;i++)
            {
                for(j=0;j<Lin;j++)
                {
                    Outlets[i][j]=Character.getNumericValue(TTabs[0][i].charAt(j));
                }
            }

            // Lire l'ensemble des Devices
            s=Lnr.readLine();
            TTabs[0] = pat.split(s);
            for(i=0;i<Nin;i++)
            {
                for(j=0;j<Lin;j++)
                {
                    Devices[i][j]=Character.getNumericValue(TTabs[0][i].charAt(j));
                }
            }

            // C'est Parti :
            // On fabrique la table des puissances de 2
            Puis2[0]=1;
            for(i=1;i<40;i++)
            {
                Puis2[i]=Puis2[i-1]*2;
            }
            
            // On crée pour chaque couple [DO] un entier et un long
            for(i=0;i<Nin;i++)
            {
                for(j=0;j<Nin;j++)
                {
                    DifDOi[i][j]=0;
                    DifDOl[i][j]=0;
                    for(k=0;k<Lin;k++)
                    {
                        if(Outlets[i][k]!=Devices[j][k])
                        {
                            DifDOi[i][j]++;
                            DifDOl[i][j]+=Puis2[k];
                        }
                    }
                }
            }
            
            // On cherche le nombre minimum de changements
            FlagOK=0;
            for(nbdif=0;nbdif<=Lin;nbdif++)
            {
                for(k=0;k<Nin;k++)
                {
                    if(DifDOi[0][k]==nbdif)
                    {
                        lgdif=DifDOl[0][k];
                        for(i=0;i<Nin;i++)
                        {
                            FlagOK=0;
                            for(j=0;j<Nin;j++)
                            {
                                if((DifDOi[i][j]==nbdif)&(DifDOl[i][j]==lgdif))
                                {
                                    FlagOK=1;
                                    break;
                                }
                            }
                            if(FlagOK==0) break;
                        }
                    }
                    if(FlagOK==1) break;
                }
                if(FlagOK==1) break;
            }
 
            // Résultat du Test Case
            sout="";
            if(FlagOK==0)sout="NOT POSSIBLE";
            if(FlagOK==1)sout=String.valueOf(nbdif);
            System.out.println("Case #"+ntc+": "+sout);
            ww.write("Case #"+ntc+": "+sout+"\n");
        }


        ww.close();
    }

}
