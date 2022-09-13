package com.example.garden_app.Bluetooth;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

import java.io.IOException;
import java.util.UUID;

public class ConnectThreadClient extends Thread{
    private final BluetoothSocket socket;
    private final BluetoothDevice device;
    private BluetoothAdapter adapter;
    private final String TAG = "BT Communication Info";
    private final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");
    private BluetoothControlManager btcm;

    public ConnectThreadClient(BluetoothDevice btd, BluetoothAdapter adpt) {
        BluetoothSocket tmp = null;
        device = btd;
        try {
            tmp = btd.createRfcommSocketToServiceRecord(MY_UUID);
        } catch (IOException e) {
            e.printStackTrace();
        }
        socket = tmp;
        adapter = adpt;
    }

    @Override
    public void run() {
        adapter.cancelDiscovery();
        try {
            socket.connect();
            System.out.println("Connection execute");
        } catch (IOException e) {
            try {
                socket.close();
                System.out.println("CONNECTION UNREACHEABLE");
            } catch (IOException ioException) {

                ioException.printStackTrace();
            }
            return;
        }
    }

    public void cancel(){
        try {
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public BluetoothSocket getSocket() {
        return socket;
    }
}

