<?php

/**
 * @file
 * Provides view field definition
 */

function resource_booking_field_views_data($field) {
  $fields = variable_get('resource_booking_fields', array());
  $data = field_views_field_default_views_data($field);

  foreach ($fields as $field_name) {
    foreach ($data as $table => $views_data) {
      if (isset($views_data[$field_name])) {
        $data[$table]['table']['group'] = t('Resource Booking');
        $data[$table][$field_name . '_nid'] = array(
          'title' => t('Resource NID'),
          'help' => t('Reference to Resource node'),
          'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
          ),
          'filter' => array(
            'handler' => 'views_handler_filter_by_resources',
          ),
          'argument' => array(
            'handler' => 'views_handler_argument_numeric',
          ),
          'relationship' => array(
            'title' => t('Resource'),
            'help' => t('Relation to Resource node'),
            'handler' => 'views_handler_relationship',
            'base' => 'node',
            'base field' => 'nid',
            'field' => $field_name . '_nid',
            'label' => t('Resource'),
          )
        );
        $data[$table][$field_name . '_sdate'] = array(
          'title' => t('Start date'),
          'help' => t('Start date of resource booking'),
          'field' => array(
            'handler' => 'views_handler_field_date',
            'click sortable' => TRUE,
          ),
          'sort' => array(
            'handler' => 'views_handler_sort_date',
          ),
          'filter' => array(
            'handler' => 'views_handler_filter_date',
          ),
        );
        $data[$table][$field_name . '_edate'] = array(
          'title' => t('End date'),
          'help' => t('End date of resource booking'),
          'field' => array(
            'handler' => 'views_handler_field_date',
            'click sortable' => TRUE,
          ),
          'sort' => array(
            'handler' => 'views_handler_sort_date',
          ),
          'filter' => array(
            'handler' => 'views_handler_filter_date',
          ),
        );
        $data[$table][$field_name . '_rb_status'] = array(
          'title' => t('Booking status'),
          'help' => t('Booking status of resource'),
          'field' => array(
            'handler' => 'views_handler_field_resource_status',
            'click sortable' => TRUE,
          ),
          'filter' => array(
            'handler' => 'views_handler_filter_by_resources_status',
          ),
          'argument' => array(
            'handler' => 'views_handler_argument_string',
          ),
        );
      }
    }
  }
  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function resource_booking_views_plugins() {
  $data = array(
    'module' => 'resource_booking', // This just tells our themes are elsewhere.
    'row' => array(
      'resource_booking_calendar_node' => array(
        'title' => t('Resource Booking Calendar Items'),
        'help' => t('Displays each selected node as a Calendar item.'),
        'handler' => 'resource_booking_calendar_plugin_row_node',
        'path' => drupal_get_path('module', 'resource_booking') . "/views",
        'base' => array('node'), // only works with 'node' as base.
        'uses options' => TRUE,
        'uses fields' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
  return $data;
}

