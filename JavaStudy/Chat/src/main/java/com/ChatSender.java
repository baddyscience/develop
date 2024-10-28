package com;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

class ChatSender {
    private static final int PORT = 62606;

    public void sendMessage(String username, String message, String broadcastAddress) throws Exception {
        DatagramSocket socket = new DatagramSocket();
        byte[] buf = message.getBytes();

        // 创建广播数据包
        DatagramPacket packet = new DatagramPacket(buf, buf.length, InetAddress.getByName(broadcastAddress), PORT);
        socket.send(packet);
        System.out.println("Sent user: " + username);
        socket.close();
    }
}
