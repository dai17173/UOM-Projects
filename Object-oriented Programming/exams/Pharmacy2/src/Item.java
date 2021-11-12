
public class Item {
	
	protected String name;
	protected int code;
	protected double kath_aksia;
	protected double ekpt;
	
	
	public Item(String name, int code, double kath_aksia, double ekpt) {
		this.name = name;
		this.code = code;
		this.kath_aksia = kath_aksia;
		this.ekpt = ekpt;
	}
	
	public double telikiAskia(double kath_aksia, double ekpt) {
		
		return kath_aksia*(1-ekpt);
	}


	public double getKath_aksia() {
		return kath_aksia;
	}

	public String getName() {
		return name;
	}
}
