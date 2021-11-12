import java.util.Scanner;
import java.util.Random;
public class Main {

	public static void main(String[] args) 
	{
		System.out.println("************ ");
		System.out.println("Tic-Tac-Toe!");
		System.out.println("************ ");
		
		System.out.println("Please enter the column (A, B or C) and then the row (1, 2, or 3) of your move.");
		System.out.println("   A B C");
		System.out.println("1 | | | |");
		System.out.println("2 | | | |");
		System.out.println("3 | | | |");
	
		Scanner input = new Scanner(System.in);
		char[][] board = new char[3][3];  
		int counter6=0;
		boolean more = true;
		Random dice = new Random();
		
		
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++) 
					board[i][j] = ' ';
		
		while (more) 
		{
		
			String thesi;
			int st,gr,i,j,counter1=0,counter2=0,counter3=0,counter4=0;
			boolean flag=true,flag2=false,flag3=false,flag4=false,flag5=false;
		
			while (flag)
			{
				System.out.println("");
				System.out.print("Player Move (X) : ");
				thesi = input.nextLine();
				System.out.println("");
				if(!"A1".equals(thesi) & !"A2".equals(thesi) & !"A3".equals(thesi) & !"B1".equals(thesi) & !"B2".equals(thesi) & !"B3".equals(thesi) & !"C1".equals(thesi) & !"C2".equals(thesi) & !"C3".equals(thesi)) 
				{
					System.out.println("Invalid Input: Please enter the column and row of your move");
					flag = true;
				}	
				else 
				{
					if ("A1".equals(thesi))
					{
						st = 0;
						gr = 0;
					}
					else if  ("A2".equals(thesi))
					{	
						st = 0;
						gr = 1;
					}	
					else if  ("A3".equals(thesi))
					{
						st = 0;
						gr = 2;
					}
					else if  ("B1".equals(thesi))
					{
						st = 1;
						gr = 0;
					}
					else if  ("B2".equals(thesi))
					{
						st = 1;
						gr = 1;
					}
					else if  ("B3".equals(thesi))
					{
						st = 1;
						gr = 2;
					}
					else if  ("C1".equals(thesi))
					{
						st = 2;
						gr = 0;
					}
					else if  ("C2".equals(thesi))
					{
						st = 2;
						gr = 1;
					}
					else 
					{
						st = 2;
						gr = 2;
					} 
					
					if (board[gr][st]=='X' || board[gr][st]=='O')
					{
						System.out.println("The space entered is already taken.");
						flag = true;
					}
					else	
					{	
						counter6 += 1;
						board[gr][st]='X';
						System.out.println("   A B C");
						for (i=0; i<3; i++)
						{	
							System.out.print(i+1  + " |");	
							for (j=0; j<3; j++) 
								System.out.print(board[i][j] +"|");
							System.out.println("");
						}
					
						for (i=0; i<3; i++)
						{
							counter3 = 0;
							counter4 = 0;
							for (j=0; j<3; j++)
							{
								if (board[j][j]=='X')
									counter3 += 1;
						    
								if (board[j][2-j]=='X')
									counter4 += 1;	
							}
						}
						for (i=0; i<3; i++)
						{
							counter1 = 0;
							counter2 = 0;
							for (j=0; j<3; j++)
							{
								if (board[i][j]=='X')
									counter1 += 1;
									if (counter1==3)
										flag2 = true;
							
								if (board[j][i]=='X')
									counter2 += 1;
								    if (counter2==3)
								    	flag3 = true;
							}	    
							
						}	
						
						flag = false;
				    }
				}
			}
			
			if (flag2 == true || flag3 == true || counter3==3 || counter4==3)
			{	
				System.out.println("You Win!");
				break;
			}
			if (counter6 == 9)
			{	
				System.out.println("");
				System.out.println("The match is even!");
				more = false;
			}
			
			while(true)
			{
				System.out.println("");	
				
				do
				{
					gr = dice.nextInt(3) ;
					st = dice.nextInt(3) ;
					
				}while(board[gr][st] == 'X' || board[gr][st] == 'O');
			    		
				if ( gr==0 && st ==0)
					System.out.println("Computer Move (O) : A1");
				else if  (gr==1 && st ==0)	
					System.out.println("Computer Move (O) : A2");	
				else if  (gr==2 && st ==0)
					System.out.println("Computer Move (O) : A3");
				else if  (gr==0 && st ==1)
					System.out.println("Computer Move (O) : B1");
				else if  (gr==1 && st ==1)
					System.out.println("Computer Move (O) : B2");
				else if  (gr==2 && st ==1)
					System.out.println("Computer Move (O) : B3");
				else if  (gr==0 && st ==2)
					System.out.println("Computer Move (O) : C1");
				else if  (gr==1 && st ==2)
					System.out.println("Computer Move (O) : C2");
				else if (gr==2 && st ==2)
					System.out.println("Computer Move (O) : C3");				
					
				counter6 += 1;
				System.out.println("");
				board[gr][st]='O';
				System.out.println("   A B C");
				for (i=0; i<3; i++)
				{	
					System.out.print(i+1  + " |");	
					for (j=0; j<3; j++) 
						System.out.print(board[i][j] +"|");
					System.out.println("");
				}
				
				for (i=0; i<3; i++)
				{
					counter3 = 0;
					counter4 = 0;
					for (j=0; j<3; j++){
						if (board[j][j]=='O')
							counter1 += 1;
						
						if (board[j][2-j]=='O')
						    counter2 += 1;
					}
				}	
						    
				for (i=0; i<3; i++)
				{
					counter1 = 0;
					counter2 = 0;
					for (j=0; j<3; j++)
					{
						if (board[i][j]=='O')
							counter1 += 1;
							if (counter1==3)
								flag4 = true;
					
						if (board[j][i]=='O')
							counter2 += 1;
						    if (counter2==3)
						    	flag5 = true;
					}	    
					
				}	
						    
				if (flag4 == true || flag5 == true || counter3==3 || counter4==3)
				{	
					System.out.println("COMPUTER Win!");
					more = false;
				}
				break;
			}	 
		}
	
	}
}
	


				
			
	  
	

	
			
			

