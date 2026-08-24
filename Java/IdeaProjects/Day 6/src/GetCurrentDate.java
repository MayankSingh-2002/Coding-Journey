//#15
import java.time.LocalDate;
import java.time.chrono.ChronoLocalDateTime;
import java.util.*;
import java.time.LocalDateTime;

public class GetCurrentDate {
    static void main(String[] args) {
        LocalDateTime now = LocalDateTime.now();
        System.out.println("Current date and time is: " + now);
    }
}
