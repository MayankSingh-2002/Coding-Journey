//#15
import java.util.*;
import java.time.ZonedDateTime;
import java.time.ZoneId;

public class GetZonedDateTIme {
    static void main(String[] args) {
        ZonedDateTime dateTime = ZonedDateTime.now(ZoneId.of("Asia/Kolkata"));

        System.out.println("Date and Time in Asia/Kolkata: " + dateTime);
    }
}
