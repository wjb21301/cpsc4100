package classLab;

public class User {
    public String name;
    public String password;
    public String email;
    

    User(){
    }
    User(String name, String password, String email){
        this.name = name;
        this.password = password;
        this.email = email;
    }
    public void setName(String name){
        this.name = name;
    }
    public String getName(){
        return this.name;
    }
    public void setPassword(String password){
        this.password = password;
    }
    public String getPassword(){
        return this.password;
    }
    public void setEmail(String email){
        this.email = email;
    }
    public String getEmail(){
        return this.email;
    }


}
