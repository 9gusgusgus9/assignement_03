import javax.swing.*;
import java.awt.*;
import java.util.function.Consumer;


public class CoffeeMachineManager {

    public static void main(String[] args) {

        final JLabel modalityLabel = new JLabel("0");
        final JLabel coffeeLabel = new JLabel("0");
        final JLabel teaLabel = new JLabel("0");
        final JLabel chocolateLabel = new JLabel("0");
        final JLabel selfCheckLabel = new JLabel("0");

        final Consumer<String> modalityConsumer = modalityLabel::setText;
        final Consumer<String> coffeeConsumer = coffeeLabel::setText;
        final Consumer<String> teaConsumer = teaLabel::setText;
        final Consumer<String> chocolateConsumer = chocolateLabel::setText;
        final Consumer<String> selfCheckConsumer = selfCheckLabel::setText;

        //Logic logic = new LogicImpl(modalityConsumer, coffeeConsumer, teaConsumer, chocolateConsumer, selfCheckConsumer);
        String[] options = {"COM1", "COM2", "COM3", "COM4", "COM5", "COM6", "COM7", "COM8"};
        
        //Creating the Frame
        JFrame frame = new JFrame("Coffer Machine Manager");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(200, 100);

        // SOUTH Panel
        JPanel southPanel = new JPanel();
        JButton refill = new JButton("Refill");

        JButton recover = new JButton("Recover");

        // CENTER Panel
        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new BoxLayout(centerPanel, BoxLayout.PAGE_AXIS));

        // Modality
        JPanel modalityPanel = new JPanel();
        modalityPanel.add(new JLabel("State: "));
        modalityPanel.add(modalityLabel);

        // Beverage
        JPanel coffeePanel = new JPanel();
        coffeePanel.add(new JLabel("Coffee: "));
        coffeePanel.add(coffeeLabel);

        JPanel teaPanel = new JPanel();
        teaPanel.add(new JLabel("Tea: "));
        teaPanel.add(teaLabel);

        JPanel chocolatePanel = new JPanel();
        chocolatePanel.add(new JLabel("Chocolate: "));
        chocolatePanel.add(chocolateLabel);

        // Self check
        JPanel selfCheckPanel = new JPanel();
        selfCheckPanel.add(new JLabel("Self Check: "));
        selfCheckPanel.add(selfCheckLabel);
        
        centerPanel.add(modalityPanel);
        centerPanel.add(coffeePanel);
        centerPanel.add(teaPanel);
        centerPanel.add(chocolatePanel);
        centerPanel.add(selfCheckPanel);
        

        southPanel.add(refill);
        southPanel.add(recover);


        // EAST Panel
        JPanel selectionPanel = new JPanel();
        selectionPanel.setLayout(new BoxLayout(selectionPanel, BoxLayout.PAGE_AXIS));
        JTextField textField = new JTextField();
        JComboBox<String> choose = new JComboBox<>(options);
        JButton startButton = new JButton("Start");
        startButton.addActionListener(e -> {
            try {
                Logic logic = new LogicImpl(choose.getItemAt(choose.getSelectedIndex()), modalityConsumer, coffeeConsumer, teaConsumer, chocolateConsumer, selfCheckConsumer);
                refill.addActionListener(ev -> logic.onRefill());
                recover.addActionListener(ev -> logic.onRecover());
                frame.getContentPane().add(BorderLayout.SOUTH, southPanel);
                frame.getContentPane().add(BorderLayout.CENTER, centerPanel);
                frame.setSize(300, 200);
                frame.getContentPane().remove(selectionPanel);
            } catch (Exception ex) {
                throw new RuntimeException(ex);
            }
        });

        selectionPanel.add(choose);
        selectionPanel.add(startButton);


        //Adding Components to the frame.
        frame.getContentPane().add(BorderLayout.CENTER, selectionPanel);
        frame.setVisible(true);
    }

}
