<?php
/**
 * @file
 * Customized calendar plugin row to handle start and end dates
 */

class resource_booking_calendar_plugin_row_node extends calendar_plugin_row_node {
  function render($row) {

    global $base_url;
    $date_info = $this->date_argument->view->date_info;

    $nid = $row->{$this->field_alias};
    if (!is_numeric($nid)) {
      return;
    }

    // Load the specified node:
    // We have to clone this or nodes on other views on this page,
    // like an Upcoming block on the same page as a calendar view,
    // will end up acquiring the values we set here.
    $node = clone($this->nodes[$nid]);
    if (empty($node)) {
      return;
    }

    //get resource booking type date fields
    $rb_fields = variable_get('resource_booking_fields', array());
    $rb_start = '';
    $rb_end = '';
    $rb_nid = 0;
    $rb_field_name = '';
    $object_fields = (array) $row;
    foreach ($rb_fields as $rb_field) {
      foreach ($object_fields as $field_name => $info) {
        if (strpos($field_name, 'node_field_data_' . $rb_field . '_nid') !== FALSE) {
          $rb_nid = $info;
          $rb_field_name = $rb_field;
        }
      }
      if (!empty($rb_nid)) {
        break;
      }
    }


    if (empty($rb_nid)) {
      debug('resouce_booking_calendar_plugin_row_node: Resource booking content not found.');
      return;
    }
    $rows = array();

      // Retrieve the field value that matched our query from the cached node.
      // Find the date and set it to the right timezone.

    $node->date_id = array();
    $item_start_date = NULL;
    $item_end_date   = NULL;

    $db_tz   = date_get_timezone_db($tz_handling, isset($item->$tz_field) ? $item->$tz_field : $date_info->display_timezone_name);
    $to_zone = date_get_timezone($tz_handling, isset($item->$tz_field) ? $item->$tz_field : $date_info->display_timezone_name);
    $granularity = 'second';
    $increment = 1;


    $lang = $node->language;
    $node->date_id = array('calendar.' . $node->nid . '.' . $field_name);
    //find the resource
    foreach ($node->{$rb_field_name}[$lang] as $rb_value) {
      if ($rb_value['nid'] == $rb_nid) {
        $rb_start = $rb_value['sdate'];
        $rb_end = $rb_value['edate'];
        break;
      }
    }

    $item_start_date = new dateObject($rb_start, $db_tz);
    $item_end_date   = new dateObject($rb_end, $db_tz);

    // If we don't have date value, go no further.
    if (empty($item_start_date)) {
      return;
    }

    // Set the item date to the proper display timezone
    $item_start_date->setTimezone(new dateTimezone($to_zone));
    $item_end_date->setTimezone(new dateTimezone($to_zone));

    $event = new stdClass();
    $event->nid = $node->nid;
    $event->title = $node->title;
    $event->type = $node->type;
    $event->date_start = $item_start_date;
    $event->date_end = $item_end_date;
    $event->db_tz = $db_tz;
    $event->to_zone = $to_zone;
    $event->granularity = $granularity;
    $event->increment = $increment;
    $event->field = $is_field ? $item : NULL;
    $event->row = $row;
    $event->node = $node;

    // All calendar row plugins should provide a date_id that the theme can use.
    $event->date_id = $node->date_id[0];

    $nodes = $this->explode_values($event);
    foreach ($nodes as $node) {
      switch ($this->options['colors']['legend']) {
        case 'type':
          $this->calendar_node_type_stripe($node);
          break;
        case 'taxonomy':
          $this->calendar_node_taxonomy_stripe($node);
          break;
        case 'group':
          $this->calendar_node_group_stripe($node);
          break;
      }
      $rows[] = $node;
    }

    return $rows;
  }
}

