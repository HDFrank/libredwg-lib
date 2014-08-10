import libxml2
import re
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

def processattr(attr):
	pattern = re.compile(r"(\d+\.\d{1,})\s{0,1}")
	if re.search(pattern, attr):
		#extract the numbers and adjust them
		extract_pattern = re.compile(r"(\d+\.\d{1,})\s{0,1}");
		result = extract_pattern.findall(attr)
		for no in range(len(result)):
			result[no] = float(result[no])

		#if its a 3d point
		if len(result) == 3:
			return "(%.2f %.2f %.2f)" % (round(result[0],2), round(result[1],2), round(result[2],2))
		elif len(result) == 2:
			return "(%.2f %.2f)" % round(round(result[0],2), round(result[1],2))
	else:
		return attr


def xmlprocess(ideal, practical):
	doc = libxml2.parseFile(ideal)

	root = doc.getRootElement()
	child = root.children

	# Let's first collect all the entities present in the file
	original_entities = []

	while child is not None:
		if child.type == "element":
			original_entities.insert(len(original_entities), child)
		child = child.next

	doc2 = libxml2.parseFile(practical)

	root2 = doc2.getRootElement()
	child2 = root2.children

	duplicate_entities = []

	while child2 is not None:
		if child2.type == "element":
			duplicate_entities.insert(len(duplicate_entities), child2)
		child2 = child2.next

	match = 0

	#Now its time for comparison, For each Dwgenentity
	for original, duplicate in zip(original_entities, duplicate_entities):
		original_attributes = {}
		duplicate_attributes = {}

		#collect original attributes
		for attr in original.properties:
			original_attributes[attr.name] = processattr(attr.content)
		

		for attr in duplicate.properties:
			duplicate_attributes[attr.name] = processattr(attr.content)

		'''
		#Now just match the type attribute and leave the rest
		if original_attributes["type"] == duplicate_attributes["type"]:
			match = 1
		'''

		#collect duplicate attributes and check if it matches with original ones
		for attr in duplicate.properties:
			try:
				duplicate_attributes[attr.name] = processattr(attr.content);
				if original_attributes[attr.name] == duplicate_attributes[attr.name]:
					match+=1
				pass
			except Exception:
				# This exception would occur when
				# We can't find the given attribute
				continue
		

	#What are the total number of attributes
	try:
		total_attr = len(original_attributes)
		if total_attr == 0:
			percent_each = 0
		else:
			percent_each = 100 / total_attr
	except NameError:
		return 0
		raise


	res_percent = percent_each*match;

	doc.freeDoc()
	doc2.freeDoc()

	return res_percent