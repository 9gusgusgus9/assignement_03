package com.example.garden_app;

public enum LedStatus {
    On, Off;

    public static LedStatus fromString(String status){
        switch (status){
            case "ON":
                return On;
            case "OFF":
                return Off;
            default:
                return Off;
        }
    }

    public static String toString(LedStatus status){
        switch (status){
            case On:
                return "ON";
            case Off:
                return "OFF";
            default:
                return "OFF";
        }
    }
}
