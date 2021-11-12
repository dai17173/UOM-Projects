
public class Cosmetic extends Item{
	
	private String marka;

	
	public Cosmetic(String name, int code, double kath_aksia, double ekpt, String marka) {
		super(name, code, kath_aksia, ekpt);
		this.marka = marka;
	}
	
	public String toString() {
		
		return ("Cosmetic Information: \n" + name + ", <" + code + ">, " + telikiAskia(kath_aksia, ekpt) + " Euro");
	}

	public String getMarka() {
		return marka;
	}
}
