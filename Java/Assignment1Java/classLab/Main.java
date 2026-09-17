package classLab;
import java.util.*;
public class Main{
public static void main(String[] args){
boolean stayLooping = true;
int choice;
int choice2;
Scanner in = new Scanner(System.in);
User u1 = new User();
while (stayLooping){
    System.out.println("=====================================");
    System.out.println();
    System.out.println("USER MANAGEMENT SYSTEM");
    System.out.println();
    System.out.println("=====================================");
    System.out.println();
    System.out.println("1. Create User");
    System.out.println();
    System.out.println("2. Update User");
    System.out.println();
    System.out.println("3. Display User Information");
    System.out.println();
    System.out.println("4.Exit");
    System.out.println("=====================================");
    System.out.println();
    System.out.print("Your Choice: ");
    choice = in.nextInt();
    in.nextLine();
    switch (choice) {
        case 1:
            System.out.println("Please enter your name");
            u1.setName(in.nextLine());
            System.out.println("Please enter an email");
            u1.setEmail(in.nextLine());
            System.out.println("Please enter a password");
            u1.setPassword(in.nextLine());
            break;
        case 2:
            System.out.println("What would you like to update? 1-name 2-email 3-password");
            choice2 = in.nextInt();
            in.nextLine();
            switch (choice2) {
                case 1:
                    System.out.println("Enter a new name. ");
                    u1.setName(in.nextLine());
                    break;
                case 2:
                    System.out.println("Enter a new email ");
                    u1.setEmail(in.nextLine());
                    break;
                case 3:
                    System.out.println("Enter a new password");
                    u1.setPassword(in.nextLine());
                    break;
                default:
                    break;
            }
            break;
        case 3:
            System.out.println("name: " + u1.getName() + " " +  "email: " + u1.getEmail());
            break;
        case 4:
            stayLooping = false;
            break;
        default:
            break;
    }


    
}
}
}