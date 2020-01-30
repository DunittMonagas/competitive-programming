
/*
*****************************************************************
*                           PROBLEMA                            *
*****************************************************************
*                  UVa 11947 - Cancer or Scorpio                *
*****************************************************************
*/

import java.util.Scanner;
import java.util.Calendar;
import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;

class Main{

	public static void main(String[] args){

		int n, dd, mm, aa;
		String aux;
		Scanner entrada= new Scanner(System.in);
		Calendar cal= GregorianCalendar.getInstance();
		SimpleDateFormat fec = new SimpleDateFormat("MM/dd/yyyy");

		n= entrada.nextInt();

		for(int i= 0; i<n; i++){

			aux= entrada.next();

			dd= Integer.parseInt(aux.substring(2, 4));
			mm= Integer.parseInt(aux.substring(0, 2));
			aa= Integer.parseInt(aux.substring(4));

			cal.set(aa, mm-1, dd);
			cal.add(Calendar.WEEK_OF_YEAR, 40);

			aa= cal.get(Calendar.YEAR);
			aux= "capricorn";

			if(cal.compareTo(new GregorianCalendar(aa, 0, 21)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 1, 19)) <= 0)
				aux= "aquarius";
			if(cal.compareTo(new GregorianCalendar(aa, 1, 20)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 2, 20)) <= 0)
				aux= "pisces";
			if(cal.compareTo(new GregorianCalendar(aa, 2, 21)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 3, 20)) <= 0)
				aux= "aries";
			if(cal.compareTo(new GregorianCalendar(aa, 3, 21)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 4, 21)) <= 0)
				aux= "taurus";
			if(cal.compareTo(new GregorianCalendar(aa, 4, 22)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 5, 21)) <= 0)
				aux= "gemini";
			if(cal.compareTo(new GregorianCalendar(aa, 5, 22)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 6, 22)) <= 0)
				aux= "cancer";
			if(cal.compareTo(new GregorianCalendar(aa, 6, 22)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 7, 21)) <= 0)
				aux= "leo";
			if(cal.compareTo(new GregorianCalendar(aa, 7, 22)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 8, 23)) <= 0)
				aux= "virgo";
			if(cal.compareTo(new GregorianCalendar(aa, 8, 24)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 9, 23)) <= 0)
				aux= "libra";
			if(cal.compareTo(new GregorianCalendar(aa, 9, 24)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 10, 22)) <= 0)
				aux= "scorpio";
			if(cal.compareTo(new GregorianCalendar(aa, 10, 23)) >= 0 && cal.compareTo(new GregorianCalendar(aa, 11, 22)) <= 0)
				aux= "sagittarius";
			

			System.out.println((i+1) + " " + fec.format(cal.getTime()) + " " + aux);
			
		}
	}

}