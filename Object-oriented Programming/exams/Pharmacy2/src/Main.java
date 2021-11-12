public class Main
{
    public static void main(String[] args) {
       
    	Pharmacy aPharmacy = new Pharmacy();
        
    	
    	Item i1 = new Medicine("farmak1", 555, 20, 0.05, true);
    	Item i2 = new Medicine("farmak1", 323, 10, 0.05, false);
    
    	Item i3 = new Cosmetic("cosm1", 444, 40, 0.1, "calvin");
    	Item i4 = new Cosmetic("cosm2", 222, 10, 0.02, "moet");
        
    	aPharmacy.add(i1);
    	aPharmacy.add(i2);
    	aPharmacy.add(i3);
    	aPharmacy.add(i4);
    	
  
    	new GUI();
    }
}
