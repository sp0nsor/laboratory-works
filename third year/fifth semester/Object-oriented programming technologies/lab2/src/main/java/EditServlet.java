import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class EditServlet extends HttpServlet{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException{
        TelephoneOperator call = null;

        try{
            call = Storage.readById(Integer.parseInt(req.getParameter("ID")));
        }catch (NumberFormatException ex){}

        resp.setCharacterEncoding("UTF-8");
        PrintWriter w = resp.getWriter();
        w.println("<HTML>");
        w.println("<HEAD>");
        w.println("<META http-equiv=\"Content-Type\"");
        w.println("      content=\"text/html; charset=UTF-8\">");
        w.println("<TITLE>Тест</TITLE>");
        w.println("</HEAD>");
        w.println("<BODY>");
        w.println("<FORM action=\"save.html\" method=\"post\">");

        if (call != null){
            w.printf("<INPUT type=\"hidden\" name=\"ID\" value=\"%s\">\n", call.getID().toString());
        }

        w.println("<P>ID:</P>");
        w.printf("<INPUT type=\"text\" name=\"ID\" value=\"%s\">\n",
                call != null ? call.getID() : new String());

        w.println("<P>callerNumber:</P>");
        w.printf("<INPUT type=\"text\" name=\"callerNumber\" value=\"%s\">\n",
                call != null ? call.getCallerNumber() : new String());

        w.println("<P>calledNumber:</P>");
        w.printf("<INPUT type=\"text\" name=\"calledNumber\" value=\"%s\">\n",
                call != null ? call.getCalledNumber() : new String());

        w.println("<P>date:</P>");
        w.printf("<INPUT type=\"text\" name=\"date\" value=\"%s\">\n",
                call != null ? call.getDate() : new String());

        w.println("<P>time:</P>");
        w.printf("<INPUT type=\"text\" name=\"time\" value=\"%s\">\n",
                call != null ? call.getTime() : new String());

        w.println("<P>duration:</P>");
        w.printf("<INPUT type=\"text\" name=\"duration\" value=\"%s\">\n",
                call != null ? call.getDuration() : new String());

        w.println("<P>costOneTariffUnit:</P>");
        w.printf("<INPUT type=\"text\" name=\"costOneTariffUnit\" value=\"%s\">\n",
                call != null ? call.getCostOneTariffUnit() : new String());

        w.println("<P>billingUnit:</P>");
        w.printf("<INPUT type=\"text\" name=\"billingUnit\" value=\"%s\">\n",
                call != null ? call.getBillingUnit() : new String());

        w.println("<BUTTON type=\"submit\">Сохранить</BUTTON>");
        w.println("<A href=\"index.html\">Назад</A>");
        w.println("</FORM>");
        w.println("</BODY>");
        w.println("</HTML>");
    }
}