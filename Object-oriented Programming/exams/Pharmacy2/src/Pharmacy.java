import java.util.ArrayList;

public class Pharmacy{
   
	private static ArrayList<Item> items = new ArrayList<Item>();

	
	public void add(Item aItem) {
		items.add(aItem);
	}


	public static ArrayList<Item> getItems() {
		return items;
	}
	
}