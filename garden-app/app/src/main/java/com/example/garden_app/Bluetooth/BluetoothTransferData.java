package com.example.garden_app.Bluetooth;

import android.app.AlertDialog;
import android.bluetooth.BluetoothSocket;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class BluetoothTransferData extends Thread{
    private BluetoothSocket socket;
    private OutputStream outputStream;
    private InputStream inputStream;
    private byte[] buffer;
    private int val;
    private BluetoothControlManager btm;

    public BluetoothTransferData(BluetoothSocket sk, BluetoothControlManager btm){
        this.socket = sk;
        OutputStream tmpOut = null;
        InputStream tmpIn = null;
        this.btm = btm;

        try {
            tmpOut = socket.getOutputStream();
            tmpIn = socket.getInputStream();
        } catch (IOException e) {
            e.printStackTrace();
        }

        outputStream = tmpOut;
        inputStream = tmpIn;
    }

    @Override
    public void run() {
        int available = 0;
        try {
            available = inputStream.available();
        } catch (IOException e) {
            e.printStackTrace();
        }
        buffer = new byte[available];
        while(true) {
            try {
                inputStream.read(buffer, 0, available);
                String string = new String(buffer);
                System.out.println(string);
                btm.getDataFromBluetooth(string);
            } catch (IOException e) {
                e.printStackTrace();
                break;
            }
        }
    }


    public void write(String data){
        try {
            outputStream.write(data.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void writeMess(String mess){
        try {
            outputStream.write(Integer.parseInt(mess));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public int getVal(){
        return this.val;
    }
}
