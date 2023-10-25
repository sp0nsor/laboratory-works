import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collection;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ListServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Collection<TelephoneOperator> calls = Storage.readAll();
        resp.setCharacterEncoding("UTF-8");
        PrintWriter w = resp.getWriter();

        w.println("<HTML>");
        w.println("<HEAD>");
        w.println("<META http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">");
        w.println("<TITLE>Тест</TITLE>");
        w.println("<STYLE>");
        w.println("TABLE {");
        w.println("border-collapse: collapse;");
        w.println("}");
        w.println("TH, TD {");
        w.println("border: 1px solid black;");
        w.println("padding: 5px 10px;");
        w.println("}");
        w.println("</STYLE>");
        w.println("</HEAD>");
        w.println("<BODY>");

        w.println("<FORM action=\"delete.html\" method=\"post\">");

        w.println("<TABLE>");

        w.print("<TR>");
        w.print("<TH>&nbsp;</TH>");
        w.print("<TH>ID</TH>");
        w.print("<TH>callerNumber</TH>");
        w.print("<TH>calledNumber</TH>");
        w.print("<TH>date</TH>");
        w.print("<TH>time</TH>");
        w.print("<TH>duration</TH>");
        w.print("<TH>costOneTariffUnit</TH>");
        w.print("<TH>billingUnit</TH>");
        w.print("<TH>costCall</TH>");
        w.println("</TR>");

        for (TelephoneOperator call : calls) {
            w.print("<TR>");

            w.printf("<TD><INPUT type=\"checkbox\" name=\"id\" value=\"%d\"></TD>", call.getID());
            w.printf("<TD><A href=\"edit.html?id=%d\">%s</A></TD>",call.getID(), call.getID());
            w.printf("<TD>%s</TD>", call.getCallerNumber());
            w.printf("<TD>%s</TD>", call.getCalledNumber());
            w.printf("<TD>%s</TD>", call.getDate());
            w.printf("<TD>%s</TD>", call.getTime());
            w.printf("<TD>%s</TD>", call.getDuration());
            w.printf("<TD>%s</TD>", call.getCostOneTariffUnit());
            w.printf("<TD>%s</TD>", call.getBillingUnit());
            w.printf("<TD>%s</TD>", call.getCostCall());

            w.println("</TR>");
        }

        w.println("</TABLE>");

        w.println("<P>");
        w.println("<A href=\"edit.html\">Добавить</A>");
        w.println("<BUTTON type=\"submit\">Удалить</BUTTON>");
        w.println("</P>");
        w.println("</FORM>");

        w.println("</BODY>");
        w.println("</HTML>");
    }
}
