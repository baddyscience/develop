package com.chattry;

import java.net.InetAddress;
import java.net.NetworkInterface;
import java.util.Enumeration;

public class BroadcastAddressFinder {

    public static void main(String[] args) {
        try {
            Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces();

            while (interfaces.hasMoreElements()) {
                NetworkInterface networkInterface = interfaces.nextElement();
                System.out.println("Interface: " + networkInterface.getDisplayName());

                if (networkInterface.isUp() && !networkInterface.isLoopback()) {
                    Enumeration<InetAddress> addresses = networkInterface.getInetAddresses();
                    while (addresses.hasMoreElements()) {
                        InetAddress address = addresses.nextElement();
                        System.out.println("  IP Address: " + address.getHostAddress());

                        if (address instanceof java.net.Inet4Address) {
                            // 计算广播地址
                            byte[] ip = address.getAddress();
                            int prefixLength = networkInterface.getInterfaceAddresses().get(0).getNetworkPrefixLength();
                            int subnetMask = 0xffffffff << (32 - prefixLength);

                            byte[] broadcast = new byte[ip.length];
                            for (int i = 0; i < ip.length; i++) {
                                broadcast[i] = (byte) (ip[i] | ~((subnetMask >> (i * 8)) & 0xff));
                            }

                            InetAddress broadcastAddress = InetAddress.getByAddress(broadcast);
                            System.out.println("  Broadcast Address: " + broadcastAddress.getHostAddress());
                        }
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
