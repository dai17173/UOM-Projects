
public class AllInclusive extends Reservation{
	
	private int meals;

	public AllInclusive(int days, int meals) {
		super(days);
		this.meals = meals;
	}
	
	public double calculateCost() {        // идио омола
		return days*(120 + meals*30);
	}
}
