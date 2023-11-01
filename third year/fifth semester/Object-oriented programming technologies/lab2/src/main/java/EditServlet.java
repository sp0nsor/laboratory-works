import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import pckg.TelephoneOperator;
public class EditServlet extends HttpServlet{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException{
        try{
            Integer ID = Integer.parseInt(req.getParameter("ID"));
            TelephoneOperator call = Storage.readById(ID);
            req.setAttribute("call", call);
        }catch (NumberFormatException ex){}

        getServletContext().getRequestDispatcher("/WEB-INF/jsp/edit.jsp").forward(req, resp);
    }
}
