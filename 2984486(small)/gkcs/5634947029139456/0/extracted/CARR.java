    import java.io.IOException;
    import java.io.InputStream;
import java.util.HashSet;
import java.util.InputMismatchException;
     
    class CARRin{
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;
    private SpaceCharFilter filter;
     
    public CARRin(InputStream stream) {
    this.stream = stream;
    }
    public interface SpaceCharFilter {
    public boolean isSpaceChar(int ch);
    }
    public int read() {
    if (numChars == -1)
    throw new InputMismatchException();
    if (curChar >= numChars) {
    curChar = 0;
    try {
    numChars = stream.read(buf);
    } catch (IOException e) {
    throw new InputMismatchException();
    }
    if (numChars <= 0)
    return -1;
    }
    return buf[curChar++];
    }
    public int readInt() {
        int c = read();
    while (isSpaceChar(c))
            c = read();
    int sgn = 1;
    if (c == '-') {
            sgn = -1;
            c = read();
    }
        int res = 0;
    do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
    public boolean isSpaceChar(int c) {
    if (filter != null)
    return filter.isSpaceChar(c);
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
    public String readString() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
    do {
            res.appendCodePoint(c);
            c = read();
        } while (!isSpaceChar(c));
    return res.toString();
    }
    }
    
    public class CARR
    {
    public static void main(String[] args) throws IOException
    {
    CARRin br=new CARRin(System.in);
    StringBuilder sb=new StringBuilder();
    int tests=br.readInt();
    for(int t=1;t<=tests;t++)
    {
    	int n=br.readInt(),l=br.readInt();
    	long MAX=1L<<l;
    	long s[]=new long[n];
    	HashSet<Long> d=new HashSet<Long>();
    	boolean flag=true;
    	for(int i=0;i<n;i++)
    	{
    		s[i]=Long.parseLong(br.readString(),2);
    	}
    	for(int i=0;i<n;i++)
    	{
    		Long dd=Long.parseLong(br.readString(),2);
    		if(!d.contains(dd))
    		{
    			d.add(dd);
    		}
    		else
    		{
    			flag=false;
    		}
    	}
    	int tr=0;
    	if(flag)
    	{
    		flag=false;
    		
    	for(;tr<MAX;tr++)
    	{
    		boolean inside=true;
    		for(int j=0;j<n;j++)
    		{
    			if(!d.contains((s[j]^tr)))
    			{
    				inside=false;
    				break;
    			}
    		}
    		if(inside)
    		{
    			flag=true;
    			break;
    		}
    	}
    	}
    	sb.append("Case #"+t+": ");
    	if(flag)
    	{
    		sb.append(Integer.bitCount(tr)+"\n");
    	}
    	else
    	{
    		sb.append("NOT POSSIBLE\n");
    	}
    }
    System.out.println(sb.toString());
    }
    
    }