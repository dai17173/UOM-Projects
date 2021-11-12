import java.awt.Color;
import java.awt.Component;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JTextField;


public class InputFrame extends JFrame {
	
	private JPanel panel;
	private JPanel diamoniPanel;
	private JPanel allInclusivePanel;
	private JPanel buttonPanel;
	
	private JLabel diamoniLabel;
	private JLabel hotelLabel;
	private JLabel allInclusiveLabel;
	
	private JList listView;
	private DefaultListModel model;
	
	private JTextField daysField;
	private JTextField mealsField;
	
	private JButton storeButton;
	private JButton calculateCostButton;
	
	private JTextField costField;
	
	//Gia na exei megaluteri emvelia.να πιανει και στον ακροατη
	private ArrayList<Hotel> hotels;

	
	public InputFrame() {
		
		panel = new JPanel();
		diamoniPanel = new JPanel();
		allInclusivePanel = new JPanel();
		buttonPanel = new JPanel();
		
		
		//Ανάγνωση των ξενοδοχείων από το αρχείο Hotels.ser
		File file = new File("Hotels.ser");
		try {
			FileInputStream fileIn = new FileInputStream(file);
			ObjectInputStream in = new ObjectInputStream(fileIn);
			
			hotels = (ArrayList<Hotel>)in.readObject();
			
			in.close();
			fileIn.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		listView = new JList();
		model = new DefaultListModel();
		
		Collections.sort(hotels);
		
		
		for(Hotel hotel: hotels)
			model.addElement(hotel.getName());
		
		listView.setModel(model);
		
		diamoniLabel = new JLabel("Stoixeia Diamonis");
		hotelLabel = new JLabel("Hotel");
		allInclusiveLabel = new JLabel("AllInclusive");
		
		daysField = new JTextField("Hmeres Diamonis");
		mealsField = new JTextField("Plithos Geumatwn (1,2,3)");
		costField = new JTextField("Synoliko Kostos");
		
		storeButton = new JButton("Apothikeusi Kratisis");
		calculateCostButton = new JButton("Ypologismos Kostous");
		
		diamoniPanel.setLayout(new BoxLayout(diamoniPanel, BoxLayout.Y_AXIS));
		diamoniLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
		diamoniPanel.add(diamoniLabel);
		hotelLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
		diamoniPanel.add(hotelLabel);
		diamoniPanel.add(listView);
		diamoniPanel.add(daysField);
		diamoniPanel.setBorder(BorderFactory.createLineBorder(Color.black));
		
		allInclusivePanel.setLayout(new GridLayout(2,0));
		allInclusivePanel.add(allInclusiveLabel);
		allInclusivePanel.add(mealsField);
		allInclusivePanel.setBorder(BorderFactory.createLineBorder(Color.black));
		
		buttonPanel.setLayout(new GridLayout(2,0));
		buttonPanel.add(storeButton);
		buttonPanel.add(calculateCostButton);
		buttonPanel.setBorder(BorderFactory.createLineBorder(Color.black));
		
		panel.add(diamoniPanel);
		panel.add(allInclusivePanel);
		panel.add(buttonPanel);
		panel.add(costField);
		
		this.setContentPane(panel);
		
		ButtonListener listener = new ButtonListener();
		storeButton.addActionListener(listener);
		calculateCostButton.addActionListener(listener);
		
		this.setVisible(true);
		this.setSize(200, 320);
		this.setLocation(550, 200);
		this.setTitle("Input");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			
			
			Hotel selectedHotel = null;
			String selectedHotelName = (String)listView.getSelectedValue(); //Αυτο καταλαβαινει τι επιλεξαμε απο τν λιστα
			for(Hotel hotel: hotels)
				if(hotel.getName().equals(selectedHotelName))
					selectedHotel = hotel;
			                //==//
			if(e.getSource().equals(storeButton)) {
				//Πατηθηκε το πληκτρο κρατησης
				String daysText = daysField.getText();
				int days = Integer.parseInt(daysText);
				
				String mealsText = mealsField.getText();
				if(mealsText.equals("")) {
					//apli kratisi
					Reservation res = new Reservation(days);
					selectedHotel.addReservation(res);
					System.out.println("Simple reservation added to " +selectedHotel.getName());
				}
				else {
					//all inclusive
					int meals = Integer.parseInt(mealsText);
					AllInclusive res = new AllInclusive(days,meals);
					selectedHotel.addReservation(res);
					System.out.println("AllInclusive reservation added to " +selectedHotel.getName());
				}
			}
			else {
				//Πατηθηκε πληκτρο συνολικης χρέωσης
				double totalCost = selectedHotel.calculateTotalCost();
				String totalCostText = Double.toString(totalCost);
				costField.setText(totalCostText);
			}	
			
		}
	}

}
