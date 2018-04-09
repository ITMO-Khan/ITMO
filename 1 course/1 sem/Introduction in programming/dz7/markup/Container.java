package markup;

import java.util.ArrayList;
import java.util.List;

public abstract class Container implements Markup {
    List<Markup> content = new ArrayList<>();

    public Container(List<Markup> list) {
        content = list;
    }

    public void toMarkdown(String spacer, StringBuilder out) {
        out.append(spacer);

        for (Markup i : content) {
            i.toMarkdown(out);
        }

        out.append(spacer);
    }

    public void toHtml(String spacer, StringBuilder out) {
        out.append("<" + spacer + ">");

        for (Markup i : content) {
            i.toHtml(out);
        }

        out.append("</" + spacer + ">");
    }

    public void toTex(String spacer, StringBuilder out) {
        out.append("\\" + spacer + "{");

        for (Markup i : content) {
            i.toTex(out);
        }

        out.append("}");
    }
}
