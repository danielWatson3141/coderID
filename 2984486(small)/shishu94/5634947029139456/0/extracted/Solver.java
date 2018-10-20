package farm;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.StringTokenizer;

public class Solver {
	static class Model {
		int bitsLength;
 		int[] lineStart;
		int[] lineEnd;
	}

	static Model[] readInputs(String path) throws IOException {
		InputStream ips = new FileInputStream(path);
		InputStreamReader ipsr = new InputStreamReader(ips);
		BufferedReader br = new BufferedReader(ipsr);
		String ligne;

		ligne = br.readLine();
		int casesCount = Integer.parseInt(ligne);
		Model[] arrayModels = new Model[casesCount];

		for (int c = 0; c < casesCount; c++) {
			arrayModels[c] = new Model();
			ligne = br.readLine();
			StringTokenizer tokenizer = new StringTokenizer(ligne);
			int nbOutlet = Integer.parseInt(tokenizer.nextToken());
			arrayModels[c].bitsLength = Integer.parseInt(tokenizer.nextToken());
			
			arrayModels[c].lineStart = new int[nbOutlet];
			arrayModels[c].lineEnd = new int[nbOutlet];
			
			ligne = br.readLine();
			tokenizer = new StringTokenizer(ligne);
			for(int i=0;i<nbOutlet;i++){
				arrayModels[c].lineStart[i] = Integer.parseInt(tokenizer.nextToken(),2);
			}
			
			ligne = br.readLine();
			tokenizer = new StringTokenizer(ligne);
			for(int i=0;i<nbOutlet;i++){
				arrayModels[c].lineEnd[i] = Integer.parseInt(tokenizer.nextToken(),2);
			}
		}

		br.close();
		return arrayModels;
	}

	static int resolve(Model model) {
		Arrays.sort(model.lineEnd);
		for(int depth = 0;depth <= model.bitsLength;depth++){
			if(testDepth(model.lineStart, model.lineEnd, depth, 0, model.bitsLength)){
				return depth;
			}
		}
		return -1;
	}

	static boolean testDepth(int[] src, int[] target, int depth, int k, int klimit){
		if(depth == 0){
			Arrays.sort(src);
			return Arrays.equals(src,target);
		}
		for(int i = k ; i<klimit;i++){
			toggleNthBit(i,src);
			if(testDepth(src, target, depth-1,i+1, klimit)){
				return true;
			}
			toggleNthBit(i, src);
		}
		return false;
	}
	
	static void toggleNthBit(int bitIndex, int[] array){
		for(int i=0;i<array.length;i++){
			array[i] ^= (1 << bitIndex);
		}
	}
	
	static void writeOutput(int[] awnsers, String path) throws IOException {
		OutputStream ops = new FileOutputStream(path);
		OutputStreamWriter opsr = new OutputStreamWriter(ops);
		BufferedWriter bw = new BufferedWriter(opsr);

		for (int c = 0; c < awnsers.length; c++) {
			if( awnsers[c] == -1){
				bw.write("Case #" + (c + 1) + ": NOT POSSIBLE\n");
			}
			else{
				bw.write("Case #" + (c + 1) + ": " + awnsers[c] + "\n");
			}
		
		}
		bw.close();
	}

	public static void main(String[] args) throws IOException {
		String inputPath = "inputs/A-small-attempt0.in";
		String outputPath = "outputs/A-small-attempt0.ou";
		Model[] models = readInputs(inputPath);
		int[] awnsers = new int[models.length];
		for (int i = 0; i < models.length; i++) {
			awnsers[i] = resolve(models[i]);
		}
		writeOutput(awnsers, outputPath);

	}
}
