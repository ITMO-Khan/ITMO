package markup;

import java.util.ArrayList;
import java.util.List;

public class Paragraph extends Container {
    public Paragraph(List<Markup> list) {
        super(list);
    }

    public void toMarkdown(StringBuilder out) {
        for (Markup i : content) {
            i.toMarkdown(out);
        }
    }

    public void toHtml(StringBuilder out) {
        for (Markup i : content) {
            i.toHtml(out);
        }
    }

    public void toTex(StringBuilder out) {
        for (Markup i : content) {
            i.toTex(out);
        }
    }
}
