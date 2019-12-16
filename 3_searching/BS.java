import java.util.*;
import java.io.*;
public class BS
{
    public static void main(String[] argv) 
    {
        try
        {
            //input data
            Scanner sc = new Scanner(new File(argv[0]));
            ArrayList<Integer> al = new ArrayList<Integer>();
            while (sc.hasNextInt()) 
                al.add(sc.nextInt());
            Collections.sort(al); //sort array
            System.out.println("data :\n"+al);
            int val = Integer.parseInt(argv[1]);
            int index = binarySearch(al, 0, al.size()-1, val);
            if(index==-1)
                System.out.println("Not found!");
            else
                System.out.println("value: "+val+" is indexed: "+index);

        }
        catch (FileNotFoundException e) 
        { e.printStackTrace(); }
    }
    public static int binarySearch(final ArrayList al,int start, int end, final int val)
    {
        int result = -1;
        while(start<end)
        {
            int middle = start + (end - start)/2; //avoid overflow
            if((Integer)al.get(middle)>val)
                end = middle - 1;
            else if((Integer)al.get(middle)<val)
                start = middle + 1;
            else
            {
                result = middle;
                break;
            }
        }
        return result;
    }
    
}
