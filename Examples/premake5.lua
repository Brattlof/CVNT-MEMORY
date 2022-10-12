group "Examples"
	project "Client"
		location "Client"
		kind "ConsoleApp"
		
		files
		{
			"Client/**.h",
			"Client/**.hpp",
			"Client/**.c",
			"Client/**.cpp"
		}
		
		links
		{
			"Memory"
		}