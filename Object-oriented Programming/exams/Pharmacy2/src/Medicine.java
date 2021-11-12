
public class Medicine extends Item{
	
	private boolean flag;

	
	public Medicine(String name, int code, double kath_aksia, double ekpt, boolean flag) {
		super(name, code, kath_aksia, ekpt);
		this.flag = flag;
	}
	
	public String toString() {
		
		if(flag == false)
			return ("Medicine Information: \n" + name + ", <" + code + ">, " + telikiAskia(kath_aksia, ekpt) + " Euro");
		else
			return ("Medicine Information: \n" + name + ", <" + code + ">, " + telikiAskia(kath_aksia, ekpt) + " Euro\n" + "Doctors require.....*");
	}
}
