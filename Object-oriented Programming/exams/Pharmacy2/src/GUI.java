import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame{
	
	private JPanel panel;
	private JTextField eisag1;
	private JTextField eisag2;
	private JButton Button1;
	private JButton Button2;
	
	
	public GUI() {
		
		panel = new JPanel();
		eisag1= new JTextField("Enter Value");
		eisag2 = new JTextField("Enter marka");
		Button1 = new JButton("Source");
		Button2 = new JButton("Print");
		
		panel.add(eisag1);
		panel.add(Button1);
		panel.add(eisag2);
		panel.add(Button2);
		
		ButtonListener listener = new ButtonListener();
		Button1.addActionListener(listener);
		Button2.addActionListener(listener);
		
		this.setContentPane(panel);
		this.setVisible(true);
		this.setSize(200, 280);
		this.setLocation(1200, 300);
		this.setTitle("Pharmacy");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			
		
			               
			if(e.getSource() == Button1) {
				String x1 = eisag1.getText();
				double x2 = Double.parseDouble(x1);
				for(int i=0; i<=3; i++) {
					if(Pharmacy.getItems().get(i).getKath_aksia() <= x2) 
						System.out.println(Pharmacy.getItems().get(i));
				}	
			}
			else 
			{
				String x3 = eisag2.getText();
				try
				{
					File f = new File("apotel.txt");
					FileWriter writer = new FileWriter(f);
					
					for(int i=0; i<=3; i++) {
						if(Pharmacy.getItems().get(i).getName().equals(x3)) {
							writer.write("Cosmetic Information: \n" + Pharmacy.getItems().get(i).getName() + ", ");
							writer.write(System.lineSeparator());
					    }
					}
					writer.close();
				}
				catch(IOException e1) {
					e1.printStackTrace();
				}
			}	
		}
	}
}


