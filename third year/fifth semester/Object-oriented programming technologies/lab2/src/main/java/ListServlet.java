import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.Comparator;
import java.util.stream.Collectors;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import pckg.TelephoneOperator;

public class ListServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Collection<TelephoneOperator> calls = Storage.readAll();
        resp.setCharacterEncoding("UTF-8");
        req.setAttribute("calls", calls);

        getServletContext().getRequestDispatcher(("/WEB-INF/jsp/index.jsp")).forward(req, resp);
    }
}
