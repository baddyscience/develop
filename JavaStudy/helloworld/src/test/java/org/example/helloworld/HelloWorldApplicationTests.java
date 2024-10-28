package org.example.helloworld;

import org.junit.jupiter.api.Test;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.jdbc.DataSourceAutoConfiguration;
import org.springframework.boot.test.context.SpringBootTest;
@SpringBootApplication(exclude= {DataSourceAutoConfiguration.class})
class HelloWorldApplicationTests {

    @Test
    void contextLoads() {
    }

}
