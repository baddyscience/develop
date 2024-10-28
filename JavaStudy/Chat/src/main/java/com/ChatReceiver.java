package com;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class ChatReceiver {
    private static final int PORT = 62606;

    public void startReceiving() throws Exception {
        DatagramSocket socket = new DatagramSocket(PORT);
        System.out.println("Listening for messages on port " + PORT);
        byte[] receiveBuf = new byte[256];

        while (true) {
            DatagramPacket receivePacket = new DatagramPacket(receiveBuf, receiveBuf.length);
            socket.receive(receivePacket);
            String receivedMessage = new String(receivePacket.getData(), 0, receivePacket.getLength());
            System.out.println("Received: " + receivedMessage);
        }
    }
}

