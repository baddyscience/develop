package com;

import java.net.InetAddress;
import java.util.Scanner;

public class ChatApp {
    public static void main(String[] args) throws Exception {
        // 获取广播地址
        String broadcastAddress = BroadcastAddressFinder.findBroadcastAddress();

        if (broadcastAddress == null) {
            System.out.println("未找到有效的广播地址。");
            return;
        } else {
            System.out.println("已找到广播地址：" + broadcastAddress);
        }

        ChatReceiver receiver = new ChatReceiver();

        // 启动接收消息的线程
        new Thread(() -> {
            try {
                receiver.startReceiving();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }).start();

        ChatSender sender = new ChatSender();
        Scanner scanner = new Scanner(System.in);
        System.out.print("username: ");
        String username = scanner.nextLine();
        while (true) {
            String message = scanner.nextLine();
            sender.sendMessage(username, message, broadcastAddress); // 使用计算出的广播地址
        }
    }
}
