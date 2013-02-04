package component;

import java.net.*;

import orderingconstruct.AnyOrderOrderingConstruct;
import orderingconstruct.ExistOrderingConstruct;
import orderingconstruct.OrderedListOrderingConstruct;

import org.jgrapht.*;
import org.jgrapht.graph.*;


public class Graph {

	public Graph() {
		// TODO Auto-generated constructor stub
	}

	public static DirectedGraph<URL, DefaultEdge> createHrefGraph()
	{
		DirectedGraph<URL, DefaultEdge> g =
				new DefaultDirectedGraph<URL, DefaultEdge>(DefaultEdge.class);

		try {
			URL amazon = new URL("[http://www.amazon.com](http://www.amazon.com)");
			URL yahoo = new URL("[http://www.yahoo.com](http://www.yahoo.com)");
			URL ebay = new URL("[http://www.ebay.com](http://www.ebay.com)");

			// add the vertices
			g.addVertex(amazon);
			g.addVertex(yahoo);
			g.addVertex(ebay);

			// add edges to create linking structure
			g.addEdge(yahoo, amazon);
			g.addEdge(yahoo, ebay);
		} catch (MalformedURLException e) {
			e.printStackTrace();
		}

		return g;
	}

	public static UndirectedGraph<String, DefaultEdge> createStringGraph()
	{
		UndirectedGraph<String, DefaultEdge> g =
				new SimpleGraph<String, DefaultEdge>(DefaultEdge.class);

		String v1 = "v1";
		String v2 = "v2";
		String v3 = "v3";
		String v4 = "v4";

		// add the vertices
		g.addVertex(v1);
		g.addVertex(v2);
		g.addVertex(v3);
		g.addVertex(v4);

		// add edges to create a circuit
		g.addEdge(v1, v2);
		g.addEdge(v2, v3);
		g.addEdge(v3, v4);
		g.addEdge(v4, v1);

		return g;
	}

	public static DirectedGraph<Object, DefaultEdge> createIntention()
	{
		DirectedGraph<Object, DefaultEdge> g = new DefaultDirectedGraph<Object, DefaultEdge>(DefaultEdge.class);

		//-- Vertices
		OrderedListOrderingConstruct oc12 = new OrderedListOrderingConstruct("OC12");
		ExistOrderingConstruct oc13 = new ExistOrderingConstruct("OC13");
		ExistOrderingConstruct oc1 = new ExistOrderingConstruct("OC1");
		ExistOrderingConstruct oc11 = new ExistOrderingConstruct("OC11");
		AnyOrderOrderingConstruct oc10 = new AnyOrderOrderingConstruct("OC10");
		

		// add the vertices
		g.addVertex(oc12);
		g.addVertex(oc13);
		g.addVertex(oc1);
		g.addVertex(oc11);
		g.addVertex(oc10);

		// add edges to create a circuit
		g.addEdge(oc13, oc1);
		g.addEdge(oc1, oc11);
		g.addEdge(oc11, oc10);
		g.addEdge(oc13, oc12);
		
		System.out.println(g.toString());

		return g;
	}
}
