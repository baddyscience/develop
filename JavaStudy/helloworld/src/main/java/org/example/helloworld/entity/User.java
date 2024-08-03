package org.example.helloworld.entity;

public class User {
    private String username;

    private String password;

    public String getUsername(){
        return username;
    }

    public void setUsername(String username){
        this.username = username;
    }

    public String getPassword(){
        return password;
    }

    public void setPassword(String password){
        this.password = password;
    }

    @Override
    public String toString(){
        return "Username: " + username + " Password: " + password;
    }
}

