package org.example.helloworld.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class helloController {

    @RequestMapping(value = "/helloworld",method = RequestMethod.GET)
    public String hello(String nickname, String phone){
        return "hello world " + nickname + " " + phone;
    }
}
