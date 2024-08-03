package org.example.helloworld.controller;

import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import java.io.File;
import java.io.IOException;

@RestController
public class FileUploadController {

    @PostMapping("/upload")
    //http://localhost:8080/upload
    public String up(String nickname, MultipartFile photo, HttpServletRequest request) throws IOException {
        System.out.println(nickname);
        //获取图片的原始名称
        System.out.println(photo.getOriginalFilename());
        //取文件类型
        System.out.println(photo.getContentType());

        System.out.println(System.getProperty("user.dir"));
        String path = request.getServletContext().getRealPath("/upload/");
        System.out.println(path);
        saveFile(photo, path);
        return "上传成功";
    }

    private void saveFile(MultipartFile photo, String path) throws IOException {
        //判断存储的目录是否存在,如果不存在则创建
        File dir = new File(path);
        if (!dir.exists()) {
            //创建目录
            dir.mkdir();
        }
        File file = new File(path + photo.getOriginalFilename());
        photo.transferTo(file);
    }

    
}
