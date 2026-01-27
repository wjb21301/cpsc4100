import java.util.Scanner;
import java.util.Random;

public class Assign1 {
    public static void main(String[] args) {
        Random r = new Random();
        Scanner s = new Scanner(System.in);
        System.out.println("Enter a nxn matrix size for multiplication");
        Integer n = s.nextInt();
        s.nextLine();
        int[][] m1 = new int[n][n];
        int[][] m2 = new int[n][n];
        for (int row = 0; row < m1.length; row++) {
            for (int col = 0; col < m1[0].length; col++) {
                m1[row][col] = r.nextInt(100);

            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%6d ", m1[i][j]);
            }   
            System.out.println();
        }  
        System.out.println("--------------------------------");
        for(int row = 0; row < m2.length; row++){
            for (int col = 0; col < m2[0].length; col++){
                m2[row][col] = r.nextInt(100);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%6d ", m2[i][j]);
            }   
            System.out.println();
        }
        System.out.println("--------------------------------");  
        int[][] result = new int[n][n];
        for (int i = 0; i < m1.length; i++){
            for(int j = 0; j < m2.length; j++){
                for(int k = 0; k < m1.length; k++){
                    result[i][j] += m1[i][k] * m2[k][j];
                }

            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%6d ", result[i][j]);
            }   
            System.out.println();
        }  
        System.out.println("Enter a name to be compared lexicograpgically");
        String name = s.nextLine();
        String smallest = name;
        String largest = name;
        String last = name;
        while(true){
            System.out.println("Enter a name to be compared lexicograpgically");
            name = s.nextLine();
             if (name.compareTo("*") == 0){
                break;
             }else if(name.compareTo(largest) > 0){
                largest = name;

             }else if(name.compareTo(smallest) < 0){
                smallest = name;
             }
             last = name;

        }
        System.out.println("Largest: " +largest);
        System.out.println("Smallest: " +smallest);
        System.out.println("last: " +last);
        s.close();

    }
}