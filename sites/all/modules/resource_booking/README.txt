The module provides resource booking capability.

The module provides generic resource booking capability. Any node can be treated as a resource and assigned
to any node.

INSTALLATION:

Extract the module in your site's modules folder and enable the module.

USAGE:
1. Creating a taxonomy that represents resource types
  1.1 Create a Taxonomy vocabulary that represents category of your resouces e.g. Resource types.
  1.2 Add terms to this resource type that represents the category of your resource e.g. Rooms, Projector, Laptops etc.
2. Create a content type that represents your resource
  2.1 Create a content type that represents your resource. e.g. call it Resources
  2.2 Add a Term reference field to your resource content type and select the above created vocabulary under Vocabulary
3. Create a content type that uses a resource 
  3.1 Create a content type that represents the entity that uses a resource e.g. Event
  3.2 Add a Resource booking field and select the above created resources content type under "Select node type"
  3.3 Select "Unlimited" under Number of values

LIMITING RESOURCE TYPES
Resource booking give the flexibility to select the resources that a user can book. This can be done by selecting
the resource type when the Resource booking field is added to a content type. However it's important to note that
the same field is reused across content types when the same terms & underlying resource content types are used
to ensure the booking status is up-to-date and no conflicts are created when segregating booking by resource types.
To do this select the resources that are allowed under "Select the allowed resource type" in the field's widget 
settings form.

ALLOWING MULTIPLE SELECTION
Certain resource types may need to allow multiple booking. This can be done by selecting the resource types
when the Resource booking field is added to a content type. To do this select the resources that are allow
multi-select under "Allow multiple" in the field's widget settings form.

PERMISSION:
1. Change resource booking status: Give to users who can change resource booking status.
2. Access resouce booking schedule: Give to users who are allowed to see resource booking schedule

RULES / ENTITY Integration:
Resource booking is integrated with the entity/rules module and therefore can be used in rules

VIEWS:
A. Calendar of Resource Booking
A resource schedlue view is included by default. However this view will have broken links and handlers as the
refered content types are not include. Therefore the following changes need to be done.
1. Click on Filter criteria -> Content: Type (in Unknown) and select the node type that uses a resource e.g. Event
2. Click on Advanced -> Contextual Filters
  2.1 Date: Date(node). Under Date Field(s), select Resource Booking: Start Date and Resource Booking: End Date
  2.2 Click on Add -> Filter for Resource Booking -> Select Resource NID
3. Click on Relationships -> Add. Filter for Resource Booking and Add Resource NID
4. Click on Field 
  4.1 Click Add. Filter for Resource Booking and add the Start Date & End Date fields
  4.2 Click on Content: Title(Title). Under Relationship select the above added relationship. This is mandatory for
the view to work. You can choose "Exclude from display" if you don't want the resource name to show up in the view 
Note: if you change the path for the view, then the same path has to be updated in the 
<Your Content Type> -> Resource booking field -> "Path for resource schedule". Do NOT change /month, /day, /year 
part of the path


B. Resources Pending Approval
A resources pending approval view is included by default. However this view will have broken links and handlers.
Therefore the following changes need to be done.
1. Click on Filter criteria
 1.1 Content: Type (in Unknown) and select the node type that uses a resource e.g. Event
 1.2 Click on Add (new filter criteria)
    1.2.1 Filter for Resource booking
    1.2.2 Select Resource booking status.
    1.2.3 Select "Requested" as the status for booking
2. Click on Relationships -> Add
  2.1 Filter for Resource Booking
  2.2 Select Resource
  2.3 Select "Require this relationship"
3. In field
  3.1 Click on Content: Title(Resource). Under Relationship select "Resource"
  3.2 Click on Add (field) -> Filter for resource booking -> Select Booking status

Views Bulk Operations:
In order to bulk approve / decline, a fix in VBO is required. Download and apply the fix available in the path
http://drupal.org/node/1180538#comment-4689296.


