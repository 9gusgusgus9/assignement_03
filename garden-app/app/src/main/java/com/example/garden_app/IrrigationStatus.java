package com.example.garden_app;

public enum IrrigationStatus {
    Open, Close, Ready;

    public static IrrigationStatus fromString(String status){
        switch (status){
            case "OPEN":
                return Open;
            case "CLOSE":
                return Close;
            case "READY":
                return Ready;
            default:
                return Close;
        }
    }

    public static String toString(IrrigationStatus status){
        switch (status){
            case Open:
                return "OPEN";
            case Close:
                return "CLOSE";
            case Ready:
                return "READY";
            default:
                return "CLOSE";
        }
    }
}
