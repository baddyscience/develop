package com;

import java.net.InetAddress;
import java.net.NetworkInterface;
import java.net.InterfaceAddress;
import java.util.Enumeration;

public class BroadcastAddressFinder {

    public static String findBroadcastAddress() {
        try {
            Enumeration<NetworkInterface> interfaces = NetworkInterface.getNetworkInterfaces();

            while (interfaces.hasMoreElements()) {
                NetworkInterface networkInterface = interfaces.nextElement();

                // 确保适配器是 Wi-Fi 适配器并且处于活动状态
                if (networkInterface.isUp() && !networkInterface.isLoopback() && networkInterface.getDisplayName().contains("Wi-Fi") || networkInterface.getDisplayName().contains("WiFi")) {
                    Enumeration<InetAddress> addresses = networkInterface.getInetAddresses();
                    while (addresses.hasMoreElements()) {
                        InetAddress address = addresses.nextElement();

                        if (address instanceof java.net.Inet4Address) {
                            for (InterfaceAddress interfaceAddress : networkInterface.getInterfaceAddresses()) {
                                if (interfaceAddress.getAddress().equals(address)) {
                                    int prefixLength = interfaceAddress.getNetworkPrefixLength();
                                    int subnetMask = (0xffffffff << (32 - prefixLength)) & 0xffffffff;

                                    byte[] ip = address.getAddress();
                                    byte[] broadcast = new byte[ip.length];

// Calculate broadcast address
                                    for (int i = 0; i < ip.length; i++) {
                                        int maskByte = (subnetMask >> (i * 8)) & 0xff;
                                        if (i == ip.length - 1) {
                                            broadcast[i] = (byte) (ip[i] | maskByte);
                                        } else {
                                            broadcast[i] = ip[i];
                                        }
                                    }

                                    InetAddress broadcastAddress = InetAddress.getByAddress(broadcast);
                                    return broadcastAddress.getHostAddress(); // 返回广播地址字符串
                                }
                            }
                        }
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null; // 如果没有找到，返回null
    }
}
