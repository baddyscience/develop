package org.example.helloworld.controller;


import org.example.helloworld.entity.User;
import org.springframework.web.bind.annotation.*;

@RestController
public class ParamsController {

    @RequestMapping(value ="/getTest1",method = RequestMethod.GET)
    //http://localhost:8080/getTest1?nickname=xxx
    public String getTest1(@RequestParam(value = "nickname",required = false)String name){
        System.out.println("nickname:"+name);
        return "GET请求";
    }

    @RequestMapping(value ="/postTest1",method = RequestMethod.POST)
    //http://localhost:8080/postTest1
    public String postTest1(User user) {
        System.out.println(user);
        return "POST请求";
    }

    @RequestMapping(value ="/postTest2",method = RequestMethod.POST)
    //http://localhost:8080/postTest2
    public String postTest2(@RequestBody User user){//json格式传入
        System.out.println(user);
        return "POST请求 - json";
    }

    @GetMapping("/test/**")
    //http://localhost:8080/test/**
    public String test(){
        return "通配符请求";
    }
}
