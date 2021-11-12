import java.io.Serializable;
import java.util.ArrayList;


public class Hotel implements Serializable, Comparable {
	  //gia na mporoun na taxinomithoun prepei na einai sigrisima metaxy tous
	private String name;
	private ArrayList<Reservation> reservations = new ArrayList<>();
	
	public void addReservation(Reservation aReservation) {
		reservations.add(aReservation);
	}

	public Hotel(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}

	public int compareTo(Object arg0) {
		Hotel other = (Hotel)arg0;
		
		return name.compareTo(other.name);
	}
	
	//Xrewsi gia kathe xenodoxeio
	public double calculateTotalCost() {
		double sum = 0;
		for(Reservation res: reservations)
			sum += res.calculateCost();
		return sum;
	}
}
