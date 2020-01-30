
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                      UVa 893 - Y3K Problem                    *
*****************************************************************
*/

import java.util.Scanner;
import java.util.Calendar;
import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;

class Main{

	public static void main(String[] args){


		int n, dd, mm, aa;
		Scanner entrada= new Scanner(System.in);
		Calendar cal= GregorianCalendar.getInstance();
		SimpleDateFormat fec = new SimpleDateFormat("d M yyyy");

		n= entrada.nextInt();
		dd= entrada.nextInt();
		mm= entrada.nextInt();
		aa= entrada.nextInt();

		while(n != 0 || dd != 0 || mm != 0 || aa != 0){

			cal.set(aa, mm-1, dd);
			cal.add(Calendar.DAY_OF_YEAR, n);

			System.out.println(fec.format(cal.getTime()));

			n= entrada.nextInt();
			dd= entrada.nextInt();
			mm= entrada.nextInt();
			aa= entrada.nextInt();

		}

	}

}
