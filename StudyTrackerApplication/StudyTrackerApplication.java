import java.util.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.io.*;

class StudyTrackerApplication
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);
        StudyTracker stobj = new StudyTracker();

        System.out.println("--------------------------------------------------------------");
        System.out.println("-------- Weclome To Study Tracker -----------------");
        System.out.println("--------------------------------------------------------------");

        int iChoice = 0;

        do
        {
            System.out.println("Please Select Appropriate Option :");
            System.out.println("1. Insert new Study Log");
            System.out.println("2. View all Study Log");
            System.out.println("3. Export all Study Log to CSV file");
            System.out.println("4. Summary of Study Log by Date");
            System.out.println("5. Summary of Study Log by Subject");
            System.out.println("6. Exit the Application");

            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                // Insert new Study Log
                case 1 :
                    stobj.InsertLog();
                    break;
                // Display all Study Log    
                case 2 :
                    stobj.DisplayLog();
                    break;
                // Export Study Log to CSV    
                case 3 :
                    stobj.ExportCSV();
                    break;
                // Summary of Study Log by Date    
                case 4 :
                    stobj.SummaryByDate();
                    break;
                // Summary of Study Log by Subject    
                case 5 :
                    stobj.SummaryBySubject();
                    break;  
                // Exit
                case 6 :
                    System.out.println("--------------------------------------------------------------");
                    System.out.println("-------- Thankyou for using our Study Tracker ----------------");
                    System.out.println("--------------------------------------------------------------");
                    break;
                // default
                default :
                    System.out.println("Please Enter Valid Option");
                    break;                          
            }
        }
        while(iChoice != 6); // End of do-while

    }   // End of main
}   // End of Main Class

// DONE
class StudyLog
{
    private LocalDate Date;
    private String Subject;
    private double Duration;
    private String Description;
    
    public StudyLog(LocalDate a, String b, double c, String d)
    {
        this.Date = a;
        this.Subject = b;
        this.Duration = c;
        this.Description = d;
    }

    public LocalDate getDate()
    {
        return this.Date;
    }

    public String getSubject()
    {
        return this.Subject;
    }

    public double getDuration()
    {
        return this.Duration;
    }

    public String getDescription()
    {
        return this.Description;
    }

    @Override
    public String toString()
    {
        return Date+" | "+Subject+" | "+Duration+" | "+Description;
    }
} // End of Class StudyLog

// DONE
class StudyTracker
{
    public ArrayList <StudyLog> Database = new ArrayList <StudyLog> ();

    public void InsertLog()
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("--------------------------------------------------------------");
        System.out.println("-------- Enter Valid Details of your Study -------------------");
        System.out.println("--------------------------------------------------------------");

        LocalDate Dateobj = LocalDate.now();

        System.out.println("Please Enter the name of the Subject (C,C++,Java,Python) :");
        String sub = sobj.nextLine();

        System.out.println("Please Enter the Time Period of your Study in hours :");
        double dur = sobj.nextDouble();
        sobj.nextLine();

        System.out.println("Please provide the description of your study:");
        String desc = sobj.nextLine();

        StudyLog studyobj = new StudyLog(Dateobj,sub,dur,desc);

        Database.add(studyobj);

        System.out.println("Study Log gets stored succesfully");
        System.out.println("--------------------------------------------------------------");
    }

    public void DisplayLog()
    {
        System.out.println("--------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("-------------- Nothing to Display ----------------------------");
            System.out.println("--------------------------------------------------------------");
            return;
        }
        
        System.out.println("---------- Log Report of the Study Tracker -------------------");
        System.out.println("--------------------------------------------------------------");

        for(StudyLog s : Database)
        {
            System.out.println(s);
        }

        System.out.println("--------------------------------------------------------------");
    }

    public void ExportCSV()
    {
        if(Database.isEmpty())
        {
            System.out.println("--------------------------------------------------------------");
            System.out.println("-------------- Nothing to Export ----------------------------");
            System.out.println("--------------------------------------------------------------");
            return;
        }

        String Filename = " StudyTracker.csv";

        try(FileWriter fwobj = new FileWriter(Filename))
        {
            fwobj.write("Date,Subject,Duration,Description\n");

            for(StudyLog s : Database)
            {
                fwobj.write(s.getDate()+","
                            +s.getSubject().replace(","," ")+","
                            +s.getDuration()+","
                            +s.getDescription().replace(","," ")+"\n");            
            }

            System.out.println("Data exported in CSV : "+Filename);
        }
        catch(Exception eobj)
        {
            System.out.println("Exception Occured in CSV handling");
        }
    }

    public void SummaryByDate()
    {
        System.out.println("--------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("----------- Nothing to Display as Database is Empty ----------");
            System.out.println("--------------------------------------------------------------");
            return;
        }

        System.out.println("----------- Summary By Date from Study Tracker ------------");
        System.out.println("--------------------------------------------------------------");

        TreeMap <LocalDate,Double> tobj = new TreeMap <LocalDate,Double> ();

        LocalDate lobj = null;
        double d = 0.0, old = 0.0;

        for(StudyLog sobj : Database)
        {
            lobj = sobj.getDate();
            d = sobj.getDuration();
            
            if(tobj.containsKey(lobj))
            {
                old = tobj.get(lobj);
                tobj.put(lobj,old+d);
            }
            else
            {
                tobj.put(lobj,d);
            }
        }

        // Display the details as per date

        for(LocalDate ld : tobj.keySet())
        {
            System.out.println("Date : "+ld+" Total Study Duration : "+tobj.get(ld));
        }
        System.out.println("--------------------------------------------------------------");
    }

    public void SummaryBySubject()
    {
        System.out.println("--------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("----------- Nothing to Display as Database is Empty ----------");
            System.out.println("--------------------------------------------------------------");
            return;
        }

        System.out.println("----------- Summary By Subject from Study Tracker ------------");
        System.out.println("--------------------------------------------------------------");

        TreeMap <String,Double> tobj = new TreeMap <String,Double> ();

        String s = null;
        double d = 0.0, old = 0.0;

        for(StudyLog sobj : Database)
        {
            s = sobj.getSubject();
            d = sobj.getDuration();
            
            if(tobj.containsKey(s))
            {
                old = tobj.get(s);
                tobj.put(s,old+d);
            }
            else
            {
                tobj.put(s,d);
            }
        }

        // Display the details as per subject

        for(String str : tobj.keySet())
        {
            System.out.println("Subject : "+str+" Total Study Duration : "+tobj.get(str));
        }
        System.out.println("--------------------------------------------------------------");
    }
} // End of Class StudyTracker