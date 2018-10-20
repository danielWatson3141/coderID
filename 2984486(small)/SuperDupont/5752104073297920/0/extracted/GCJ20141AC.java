/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package gcj20141ac;

import java.io.*;
import java.util.regex.Pattern;

/**
 *
 * @author Nous
 */
public class GCJ20141AC {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException
    {
        // TODO code application logic here
        Reader rr;
        Writer ww;
        LineNumberReader Lnr;
        String s;
        String[][] TTabs;
        long a,b,c;
        int i,j,ntc;
        Pattern pat;

         TTabs = new String[100][];

        int NbTestCases;
        String sout;
        int  FlagOK;

        // Pi x 10e30, au cas où :
        // BigNbr bnPIe30;
        // bnPIe30 = new BigNbr("3141592653589793238462643383279");

        // Variables Fonctionnelles liées au Test Case :
        int Nin;
        int[] NbPerm;
        double PtMilieu, Effort, Poids;
        
        NbPerm = new int [1000];


        //       ll=new long[100];
        pat =  Pattern.compile(" +"); // Pour séparer les mots
        //       pat =  Pattern.compile(" *"); // Pour séparer chaque caractère
        //               (attention : commence alors par "")
        // Titre
        System.out.println("2014-1A-C");

        // Nombre de cas
        rr=new InputStreamReader(new FileInputStream("C-small-attempt0.in"),
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
            

            // Intégrer les nombres
            s=Lnr.readLine();
            TTabs[0] = pat.split(s);
            Poids=0;
            for(i=0;i<Nin;i++)
            {
                NbPerm[i] = Integer.parseInt(TTabs[0][i]);
                Poids+=NbPerm[i];
            }

            // C'est Parti :
            // Calcul du barycentre :
            PtMilieu = ((double)Nin)/2;
            Effort=0;
            for(i=0;i<Nin;i++)
            {
                Effort+=(((double)i)-PtMilieu+0.5)*NbPerm[i];
            }
            Effort=Effort/PtMilieu/Poids;
            
 
            // Résultat du Test Case
            sout="";
            if(Math.abs(Effort)<0.01)sout ="GOOD";
            else sout="BAD";
            System.out.println("Case #"+ntc+": "+sout);
            ww.write("Case #"+ntc+": "+sout+"\n");
        }


        ww.close();
    }

}
